#ifndef TEXTURE2D_CUBE_H
#define TEXTURE2D_CUBE_H

#include "ThirdPersonEngine.h"
#include "UniformCamera.h"
#include "OpenGLESTexture2D.h"
#include "OpenGLESMaterial.h"
#include "OpenGLESCube.h"

class Shader;

BEGIN_NAMESPACE(OpenGLESEngine)

class Texture2DCube : public ThirdPersonEngine {
public:
    Texture2DCube();

    ~Texture2DCube();

    void prepareMyObjects();

    void render();

private:
    void prepareTextures();

    void prepareShaders();

    void createCube();

    void createUniformCamera();

    void createCubeMaterial();

    void startAutoRotation();

private:
    OpenGLESTemplate::OpenGLESCube* m_cube = nullptr;
    OpenGLESTemplate::UniformCamera* m_uniformCamera = nullptr;
    OpenGLESTemplate::OpenGLESTexture2D* m_textureA = nullptr;
    OpenGLESTemplate::OpenGLESTexture2D* m_textureB = nullptr;
    OpenGLESTemplate::OpenGLESMaterial* m_cubeMaterial = nullptr;

    Shader *m_shader = nullptr;

    bool m_autoRotation = false;
};


END_NAMESPACE(OpenGLESEngine)

#endif