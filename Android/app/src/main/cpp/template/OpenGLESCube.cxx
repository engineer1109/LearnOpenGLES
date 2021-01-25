//
// Created by wjl on 21-1-26.
//

#include "OpenGLESCube.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

Cube::Cube() {}

Cube::~Cube() noexcept {}

void Cube::setSize(float a, float b, float c){
    m_a = a;
    m_b = b;
    m_c = c;
}

void Cube::update(){
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    //updateUniforms(true);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::generateVertexs() {
    std::vector<Vertex> vertices =
            {
                    {{1.0f * m_a,  1.0f,  1.0f},  {1.0f, 1.0f}, {0.0f,  0.0f,  1.0f}},
                    {{-1.0f * m_a, -1.0f, 1.0f},  {0.0f, 0.0f}, {0.0f,  0.0f,  1.0f}},
                    {{-1.0f * m_a, 1.0f,  1.0f},  {0.0f, 1.0f}, {0.0f,  0.0f,  1.0f}},
                    {{1.0f * m_a,  1.0f,  1.0f},  {1.0f, 1.0f}, {0.0f,  0.0f,  1.0f}},
                    {{1.0f * m_a,  -1.0f, 1.0f},  {1.0f, 0.0f}, {0.0f,  0.0f,  1.0f}},
                    {{-1.0f * m_a, -1.0f, 1.0f},  {0.0f, 0.0f}, {0.0f,  0.0f,  1.0f}},

                    {{1.0f * m_a,  1.0f,  -1.0f}, {0.0f, 1.0f}, {0.0f,  0.0f,  -1.0f}},
                    {{-1.0f * m_a, 1.0f,  -1.0f}, {1.0f, 1.0f}, {0.0f,  0.0f,  -1.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {1.0f, 0.0f}, {0.0f,  0.0f,  -1.0f}},
                    {{1.0f * m_a,  1.0f,  -1.0f}, {0.0f, 1.0f}, {0.0f,  0.0f,  -1.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {1.0f, 0.0f}, {0.0f,  0.0f,  -1.0f}},
                    {{1.0f * m_a,  -1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f,  0.0f,  -1.0f}},

                    {{1.0f * m_a,  1.0f,  1.0f},  {0.0f, 1.0f}, {1.0f,  0.0f,  0.0f}},
                    {{1.0f * m_a,  -1.0f, -1.0f}, {1.0f, 0.0f}, {1.0f,  0.0f,  0.0f}},
                    {{1.0f * m_a,  -1.0f, 1.0f},  {0.0f, 0.0f}, {1.0f,  0.0f,  0.0f}},
                    {{1.0f * m_a,  1.0f,  1.0f},  {0.0f, 1.0f}, {1.0f,  0.0f,  0.0f}},
                    {{1.0f * m_a,  1.0f,  -1.0f}, {1.0f, 1.0f}, {1.0f,  0.0f,  0.0f}},
                    {{1.0f * m_a,  -1.0f, -1.0f}, {1.0f, 0.0f}, {1.0f,  0.0f,  0.0f}},

                    {{-1.0f * m_a, 1.0f,  1.0f},  {1.0f, 1.0f}, {-1.0f, 0.0f,  0.0f}},
                    {{-1.0f * m_a, -1.0f, 1.0f},  {1.0f, 0.0f}, {-1.0f, 0.0f,  0.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {0.0f, 0.0f}, {-1.0f, 0.0f,  0.0f}},
                    {{-1.0f * m_a, 1.0f,  1.0f},  {1.0f, 1.0f}, {-1.0f, 0.0f,  0.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {0.0f, 0.0f}, {-1.0f, 0.0f,  0.0f}},
                    {{-1.0f * m_a, 1.0f,  -1.0f}, {0.0f, 1.0f}, {-1.0f, 0.0f,  0.0f}},

                    {{1.0f * m_a,  1.0f,  1.0f},  {1.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
                    {{-1.0f * m_a, 1.0f,  1.0f},  {0.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
                    {{-1.0f * m_a, 1.0f,  -1.0f}, {0.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},
                    {{1.0f * m_a,  1.0f,  1.0f},  {1.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
                    {{-1.0f * m_a, 1.0f,  -1.0f}, {0.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},
                    {{1.0f * m_a,  1.0f,  -1.0f}, {1.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},

                    {{1.0f * m_a,  -1.0f, 1.0f},  {1.0f, 1.0f}, {0.0f,  -1.0f, 0.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f,  -1.0f, 0.0f}},
                    {{-1.0f * m_a, -1.0f, 1.0f},  {0.0f, 1.0f}, {0.0f,  -1.0f, 0.0f}},
                    {{1.0f * m_a,  -1.0f, 1.0f},  {1.0f, 1.0f}, {0.0f,  -1.0f, 0.0f}},
                    {{1.0f * m_a,  -1.0f, -1.0f}, {1.0f, 0.0f}, {0.0f,  -1.0f, 0.0f}},
                    {{-1.0f * m_a, -1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f,  -1.0f, 0.0f}},
            };

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
    // color attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);  //unbind
}

END_NAMESPACE(OpenGLESTemplate)
