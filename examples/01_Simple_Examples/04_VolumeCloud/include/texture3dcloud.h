#ifndef TEXTURE3DCLOUD_H
#define TEXTURE3DCLOUD_H
#include "opengles_basicengine_texture3dplane.h"
class Texture3DCloud : public OpenGLESTemplate::Texture3DPlane {
public:
    Texture3DCloud(uint32_t width, uint32_t height, uint32_t depth);
    ~Texture3DCloud();

    void prepare();
    void update();

    void prepareTextures();
    void prepareShaders();
    void prepareUniforms();
    void updateUniforms();

public:
    glm::mat4 m_viewMat;
    struct {
        glm::mat4 model;
    } m_modelVolume;
    struct ObjectCamera {
        float *zoom = nullptr;
        glm::vec3 *rotation = nullptr;
        glm::vec3 *cameraPos = nullptr;
    } m_camera;

protected:
    uint32_t m_width = 0;
    uint32_t m_height = 0;
    uint32_t m_depth = 0;
    uint8_t *m_imgData = nullptr;
    OpenGLESTemplate::Texture2D m_pseudoColor;
};
#endif // TEXTURE3DCLOUD_H
