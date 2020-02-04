#ifndef VOLUMECLOUD_H
#define VOLUMECLOUD_H
#include "opengles_basicengine.h"
class Texture3DCloud;
class VolumeCloud : public OpenGLESBasicEngine {
public:
    VolumeCloud();
    ~VolumeCloud();

    void prepare();
    void render();

protected:
    void prepareObjects();

private:
    Texture3DCloud *m_cloud = nullptr;
};
#endif
