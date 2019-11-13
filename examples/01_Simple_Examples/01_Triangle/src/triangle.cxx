#include <iostream>
#include "shader_m.h"
#include "triangle.h"

Triangle::Triangle(){
    zoom=-2;
}

void Triangle::prepare(){
    glEnable(GL_DEPTH_TEST);
    OpenGLESBase::prepare();
    prepareShaders();
    generateVertexs();
    prepareUniforms();
}

void Triangle::render(){
    glViewport(0,0,uint32_t(width),uint32_t(height));
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glFlush();
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    updateUniforms();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::generateVertexs(){
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top

    };

    unsigned int VBO;
    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(m_vertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);  //unbind
}

void Triangle::prepareShaders(){
    m_shader= new Shader("../data/shaders/Simple_01_Triangle/01_Triangle/triangle.vert",
                     "../data/shaders/Simple_01_Triangle/01_Triangle/triangle.frag");
}

void Triangle::prepareUniforms(){
    m_uboVS.projection = glm::perspective(glm::radians(60.f), float(width)/float(height), 0.001f, 256.0f);
    m_uboVS.model=glm::mat4(1.0);
}

void Triangle::updateUniforms(){
    m_shader->setMat4("ubo.projection", m_uboVS.projection);
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, zoom));
    m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), cameraPos);
    m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    m_shader->setMat4("ubo.model", m_uboVS.model);
}
