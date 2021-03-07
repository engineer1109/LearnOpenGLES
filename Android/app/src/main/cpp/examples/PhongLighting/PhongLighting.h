//
// Created by wjl on 20-12-13.
//

#ifndef OPENGLESDEMO_PHONGLIGHTING_H
#define OPENGLESDEMO_PHONGLIGHTING_H

#include "ThirdPersonEngine.h"
#include "UniformCamera.h"
#include "OpenGLESCube.h"
#include "OpenGLESTexture2D.h"
#include "OpenGLESMaterial.h"

class Shader;

class PhongLightingCube;

BEGIN_NAMESPACE(OpenGLESEngine)

class PhongLighting : public ThirdPersonEngine {
public:
    PhongLighting();
    virtual ~PhongLighting();

    void prepareMyObjects();

    void render();

    //void createPhongLightingCube();

    void prepareTextures();

    void prepareShaders();

    void createCube();

    void createUniformCamera();

    void createCubeMaterial();

private:
    //PhongLightingCube* m_PhongLightingCube = nullptr;
    Shader *m_shader = nullptr;
    OpenGLESTemplate::OpenGLESCube* m_cube = nullptr;
    OpenGLESTemplate::UniformCamera* m_uniformCamera = nullptr;
    OpenGLESTemplate::OpenGLESTexture2D* m_textureA = nullptr;
    OpenGLESTemplate::OpenGLESTexture2D* m_textureB = nullptr;
    OpenGLESTemplate::OpenGLESMaterial* m_cubeMaterial = nullptr;
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESDEMO_PHONGLIGHTING_H
