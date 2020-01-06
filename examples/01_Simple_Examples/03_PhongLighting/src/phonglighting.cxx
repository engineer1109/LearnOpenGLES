#include "cube.h"
#include "phonglighting.h"
PhongLighting::PhongLighting(){
    zoom=-2;
    title="PhongLighting Examples";
}

PhongLighting::~PhongLighting(){
    if(m_cube){
        delete m_cube;
        m_cube=nullptr;
    }
}

void PhongLighting::prepare(){
    glEnable(GL_DEPTH_TEST);
    prepareBase();
    prepareObjects();
}

void PhongLighting::render(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0,0,uint32_t(width),uint32_t(height));

    m_cube->update();

    glFlush();
}

void PhongLighting::prepareObjects(){
    m_cube=new Cube();
    m_cube->setScreenPtr(&width,&height);
    m_cube->m_camera.pZoom=&zoom;
    m_cube->m_camera.pCameraPos=&cameraPos;
    m_cube->m_camera.pRotation=&rotation;
    m_cube->prepare();
}
