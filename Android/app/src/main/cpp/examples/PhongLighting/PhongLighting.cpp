//
// Created by wjl on 20-12-13.
//

#include "PhongLighting.h"

#include "PhongLightingCube.h"

BEGIN_NAMESPACE(OpenGLESEngine)

PhongLighting::PhongLighting() : ThirdPersonEngine() {
    m_zoom = -4.f;
}

PhongLighting::~PhongLighting() {}

void PhongLighting::prepareMyObjects() {
    glEnable(GL_DEPTH_TEST);
    createPhongLightingCube();
}

void PhongLighting::render() {
    updateCamera();

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));

    m_PhongLightingCube->update();

    glFlush();
}

void PhongLighting::createPhongLightingCube() {
    m_PhongLightingCube = new PhongLightingCube();
    m_PhongLightingCube->setAssetManager(m_asset);
    m_PhongLightingCube->setSize(1.f, 1.f, 1.f);
    m_PhongLightingCube->setScreenPtr(&m_width, &m_height);
    m_PhongLightingCube->setZoomPtr(&m_zoom);
    m_PhongLightingCube->setRotationPtr(&m_rotation);
    m_PhongLightingCube->setCameraPosPtr(&m_cameraPos);
    m_PhongLightingCube->prepare();
}

END_NAMESPACE(OpenGLESEngine)
