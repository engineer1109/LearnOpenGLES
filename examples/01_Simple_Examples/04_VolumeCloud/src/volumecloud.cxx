#include "texture3dcloud.h"

#include "volumecloud.h"
VolumeCloud::VolumeCloud() {
    zoom = 4.f;
    title = "VolumeCloud Examples";
}

VolumeCloud::~VolumeCloud() {
    if (m_cloud) {
        delete m_cloud;
        m_cloud = nullptr;
    }
}

void VolumeCloud::prepare() {
    glEnable(GL_DEPTH_TEST);
    prepareBase();
    prepareObjects();
}

void VolumeCloud::render() {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0, 0, uint32_t(width), uint32_t(height));

    m_cloud->update();

    glFlush();
}

void VolumeCloud::prepareObjects() {
    m_cloud = new Texture3DCloud(512, 512, 512);
    m_cloud->setScreenPtr(&width, &height);
    m_cloud->m_camera.zoom = &zoom;
    m_cloud->m_camera.cameraPos = &cameraPos;
    m_cloud->m_camera.rotation = &rotation;
    m_cloud->prepare();
}
