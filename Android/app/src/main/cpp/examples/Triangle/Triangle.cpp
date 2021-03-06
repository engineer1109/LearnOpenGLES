//
// Created by wjl on 20-9-6.
//

#include "Triangle.h"
#include "shader_m.h"

#include "myobjects/TriangleObject.h"

BEGIN_NAMESPACE(OpenGLESEngine)
Triangle::Triangle() : ThirdPersonEngine() {
}

Triangle::~Triangle() {
    delete_ptr(m_triangleObject);
    delete_ptr(m_shader);
}

void Triangle::prepareMyObjects() {
    prepareShaders();

    createTriangle();
    createUniformCamera();
}

void Triangle::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/01_Triangle/triangle.vert",
                          "shaders/Simple_01_Examples/01_Triangle/triangle.frag", m_asset);
}

void Triangle::render() {
    updateCamera();

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.2, 0.3, 1.0);

    m_shader->use();
    m_uniformCamera->update();
    m_triangleObject->update();

    glFlush();
}

void Triangle::createTriangle() {
    m_triangleObject = new TriangleObject();
    m_triangleObject->prepare();
}

void Triangle::createUniformCamera() {
    m_uniformCamera = new OpenGLESTemplate::UniformCamera();
    m_uniformCamera->setScreenSizePtr(&m_width, &m_height);
    m_uniformCamera->setRotationPtr(&m_rotation);
    m_uniformCamera->setCameraPosPtr(&m_cameraPos);
    m_uniformCamera->setZoomPtr(&m_zoom);
    m_uniformCamera->setShaders({m_shader});
    m_uniformCamera->prepare();
}
END_NAMESPACE(OpenGLESEngine)