//
// Created by wjl on 20-9-6.
//

#include "Triangle.h"
#include "shader_m.h"

BEGIN_NAMESPACE(OpenGLESEngine)
Triangle::Triangle() {
    zoom = -2;
}

Triangle::~Triangle() {}

void Triangle::prepare() {
    prepareBase();
    prepareShaders();
    generateVertexs();
    prepareUniforms();
}

void Triangle::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/01_Triangle/triangle.vert",
                          "shaders/Simple_01_Examples/01_Triangle/triangle.frag", m_asset);
}

void Triangle::generateVertexs() {
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    std::vector<Vertex> vertices =
            {
                    {{0.0f,  1.0f,  0.0f}, {1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
                    {{1.0f,  -1.0f, 0.0f}, {0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
                    {{-1.0f, -1.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}},
            };

//    float vertices[] =
//    {
//         0.0f,  -1.0f, 0.0f , 1.0f, 1.0f , 0.0f, 0.0f, 1.0f,
//         1.0f,  1.0f, 0.0f , 0.0f, 1.0f , 0.0f, 0.0f, 1.0f ,
//         -1.0f, 1.0f, 0.0f , 1.0f, 0.0f , 0.0f, 0.0f, 1.0f ,
//    };

    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(m_vertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(),
                 GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // UV attribute , not use in this example
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Normal attribute used as color point
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (5 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);  //unbind
}

void Triangle::prepareUniforms() {
    m_uboVS.projection = glm::perspective(glm::radians(60.f), float(m_width) / float(m_height),
                                          0.001f, 256.0f);
    m_uboVS.model = glm::mat4(1.0);
    updateUniforms(true);
}

void Triangle::updateUniforms(bool update) {
    if (update) {
        m_shader->setMat4("ubo.projection", m_uboVS.projection);
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, zoom));
        m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), cameraPos);
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.x),
                                    glm::vec3(1.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.y),
                                    glm::vec3(0.0f, 1.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.z),
                                    glm::vec3(0.0f, 0.0f, 1.0f));
    }
    m_shader->setMat4("ubo.model", m_uboVS.model);
}

void Triangle::render() {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.2, 0.3, 1.0);

    m_shader->use();
    glBindVertexArray(m_vertexArray);
    updateUniforms(true);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glFlush();
}
END_NAMESPACE(OpenGLESEngine)