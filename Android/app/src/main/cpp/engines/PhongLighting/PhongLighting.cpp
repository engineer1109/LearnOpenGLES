//
// Created by wjl on 20-12-13.
//

#include "PhongLighting.h"

#include "PhongLightingCube.h"

BEGIN_NAMESPACE(OpenGLESEngine)

PhongLighting::PhongLighting(){}

PhongLighting::~PhongLighting() {}

void PhongLighting::prepare() {
    glEnable(GL_DEPTH_TEST);
    createPhongLightingCube();
}

void PhongLighting::render() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));

    m_PhongLightingCube->update();
}

void PhongLighting::createPhongLightingCube() {
    m_PhongLightingCube = new PhongLightingCube();
    m_PhongLightingCube->setAssetManager(m_asset);
    m_PhongLightingCube->setSize(1.f,1.f,1.f);
    m_PhongLightingCube->prepare();
}

END_NAMESPACE(OpenGLESEngine)
