//
// Created by wjl on 20-12-13.
//

#include "PhongLighting.h"

#include "OpenGLESCube.h"

BEGIN_NAMESPACE(OpenGLESEngine)

PhongLighting::PhongLighting(){}

PhongLighting::~PhongLighting() {}

void PhongLighting::prepare() {
    glEnable(GL_DEPTH_TEST);
    createCube();
}

void PhongLighting::render() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));
}

void PhongLighting::createCube() {
    m_Cube = new OpenGLESTemplate::Cube();
    m_Cube->setSize(1.f,1.f,1.f);
    m_Cube->prepare();
}

END_NAMESPACE(OpenGLESEngine)
