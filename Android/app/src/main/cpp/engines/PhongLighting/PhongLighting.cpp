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
    prepareBase();
    createPhongLightingCube();
}

void PhongLighting::render() {

    defaultTouchOperation();

    if (m_touchMode == TouchMode::SINGLE) {
        if (m_mousePos[0].x > m_mousePosOld[0].x) {
            m_rotation.y += 1.f;
        } else if (m_mousePos[0].x < m_mousePosOld[0].x) {
            m_rotation.y -= 1.f;
        }
        if (m_mousePos[0].y > m_mousePosOld[0].y) {
            m_rotation.x += 1.f;
        } else if (m_mousePos[0].y < m_mousePosOld[0].y) {
            m_rotation.x -= 1.f;
        }
    } else if (m_touchMode == TouchMode::DOUBLE) {
        m_zoom = m_distance + m_baseZoom;
    }
    m_mousePosOld[0] = m_mousePos[0];

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
    m_PhongLightingCube->setSize(1.f,1.f,1.f);
    m_PhongLightingCube->setScreenPtr(&m_width,&m_height);
    m_PhongLightingCube->setZoomPtr(&m_zoom);
    m_PhongLightingCube->setRotationPtr(&m_rotation);
    m_PhongLightingCube->setCameraPosPtr(&m_cameraPos);
    m_PhongLightingCube->prepare();
}

END_NAMESPACE(OpenGLESEngine)
