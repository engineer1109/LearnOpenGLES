#include "Texture2DCube.h"

#include "stb_image_aug.h"
#include "AssetReader.h"

BEGIN_NAMESPACE(OpenGLESEngine)

Texture2DCube::Texture2DCube() : ThirdPersonEngine() {
    m_zoom = -4.f;
}

Texture2DCube::~Texture2DCube() {
    delete_ptr(m_textureA);
    delete_ptr(m_textureB);
    delete_ptr(m_shader);
    delete_ptr(m_cubeMaterial);
    delete_ptr(m_cube);
}

void Texture2DCube::prepareMyObjects() {
    glEnable(GL_DEPTH_TEST);
    prepareTextures();
    prepareShaders();

    createCube();
    createUniformCamera();
    createCubeMaterial();
    //prepared=true;
}

void Texture2DCube::render() {
    updateCamera();

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(m_width), uint32_t(m_height));

    m_uniformCamera->update();

    m_cubeMaterial->update();

    m_cube->update();

    startAutoRotation();

    glFlush();
}

void Texture2DCube::prepareTextures() {
    m_textureA = new OpenGLESTemplate::OpenGLESTexture2D();
    m_textureB = new OpenGLESTemplate::OpenGLESTexture2D();
    m_textureA->loadFromFile("textures/container.png", m_asset);
    m_textureB->loadFromFile("textures/awesomeface.png", m_asset);
}

void Texture2DCube::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/02_Texture2DCube/cube.vert",
                          "shaders/Simple_01_Examples/02_Texture2DCube/cube.frag", m_asset);
    m_shader->use();
}

void Texture2DCube::createCube() {
    m_cube = new OpenGLESTemplate::OpenGLESCube();
    m_cube->prepare();
}

void Texture2DCube::createUniformCamera() {
    m_uniformCamera = new OpenGLESTemplate::UniformCamera();
    m_uniformCamera->setScreenSizePtr(&m_width, &m_height);
    m_uniformCamera->setRotationPtr(&m_rotation);
    m_uniformCamera->setCameraPosPtr(&m_cameraPos);
    m_uniformCamera->setZoomPtr(&m_zoom);
    m_uniformCamera->setShaders({m_shader});
    m_uniformCamera->prepare();
}

void Texture2DCube::createCubeMaterial() {
    m_cubeMaterial = new OpenGLESTemplate::OpenGLESMaterial();
    m_cubeMaterial->setShader(m_shader);
    m_cubeMaterial->setTextures({{0, "texture1", m_textureA},
                                 {1, "texture2", m_textureB}});
    m_cubeMaterial->prepare();
}

void Texture2DCube::startAutoRotation() {
//    if(m_autoRotation){
//        rotation.y++;
//    }
}

END_NAMESPACE(OpenGLESEngine)
