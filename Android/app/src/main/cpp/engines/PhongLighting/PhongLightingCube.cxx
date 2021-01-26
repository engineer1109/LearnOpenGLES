//
// Created by wjl on 21-1-27.
//

#include "PhongLightingCube.h"

PhongLightingCube::PhongLightingCube() : OpenGLESTemplate::Cube() {

}

PhongLightingCube::~PhongLightingCube(){

}

void PhongLightingCube::prepare() {
    generateVertexs();
    prepareShaders();
}

void PhongLightingCube::update() {
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    //updateUniforms(true);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void PhongLightingCube::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/03_PhongLighting/cube.vert",
                          "shaders/Simple_01_Examples/03_PhongLighting/cube.frag", m_asset);
    m_shader->use();
    m_shader->setInt("texture1", 0);
    m_shader->setInt("texture2", 1);
}
