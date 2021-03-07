//
// Created by wjl on 20-12-13.
//

#include "PhongLighting.h"

BEGIN_NAMESPACE(OpenGLESEngine)

PhongLighting::PhongLighting() : ThirdPersonEngine() {
    m_zoom = -4.f;
}

PhongLighting::~PhongLighting() {
    delete_ptr(m_textureA);
    delete_ptr(m_textureB);
    delete_ptr(m_shader);
    delete_ptr(m_cubeMaterial);
    delete_ptr(m_cube);
}

void PhongLighting::prepareMyObjects() {
    glEnable(GL_DEPTH_TEST);
    //createPhongLightingCube();
    prepareTextures();
    prepareShaders();

    createCube();
    createUniformCamera();
    createCubeMaterial();
}

void PhongLighting::render() {
    updateCamera();

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));

    //m_PhongLightingCube->update();
    m_uniformCamera->update();

    m_cubeMaterial->update();

    m_cube->update();

    glFlush();
}

//void PhongLighting::createPhongLightingCube() {
//    m_PhongLightingCube = new PhongLightingCube();
//    m_PhongLightingCube->setAssetManager(m_asset);
//    m_PhongLightingCube->setSize(1.f, 1.f, 1.f);
//    m_PhongLightingCube->setScreenPtr(&m_width, &m_height);
//    m_PhongLightingCube->setZoomPtr(&m_zoom);
//    m_PhongLightingCube->setRotationPtr(&m_rotation);
//    m_PhongLightingCube->setCameraPosPtr(&m_cameraPos);
//    m_PhongLightingCube->prepare();
//}

void PhongLighting::prepareTextures() {
    m_textureA = new OpenGLESTemplate::OpenGLESTexture2D();
    m_textureB = new OpenGLESTemplate::OpenGLESTexture2D();
    m_textureA->loadFromFile("textures/container.png", m_asset);
    m_textureB->loadFromFile("textures/awesomeface.png", m_asset);
}

void PhongLighting::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/03_PhongLighting/cube.vert",
                          "shaders/Simple_01_Examples/03_PhongLighting/cube.frag", m_asset);
    m_shader->use();
}

void PhongLighting::createCube() {
    m_cube = new OpenGLESTemplate::OpenGLESCube();
    m_cube->prepare();
}

void PhongLighting::createUniformCamera() {
    m_uniformCamera = new OpenGLESTemplate::UniformCamera();
    m_uniformCamera->setScreenSizePtr(&m_width, &m_height);
    m_uniformCamera->setRotationPtr(&m_rotation);
    m_uniformCamera->setCameraPosPtr(&m_cameraPos);
    m_uniformCamera->setZoomPtr(&m_zoom);
    m_uniformCamera->setShaders({m_shader});
    m_uniformCamera->prepare();
}

void PhongLighting::createCubeMaterial() {
    m_cubeMaterial = new OpenGLESTemplate::OpenGLESMaterial();
    m_cubeMaterial->setShader(m_shader);
    m_cubeMaterial->setTextures({{0, "texture1", m_textureA},
                                 {1, "texture2", m_textureB}});
    m_cubeMaterial->prepare();
}

END_NAMESPACE(OpenGLESEngine)
