#include "OpenGLESMeshObject.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
OpenGLESMeshObject::OpenGLESMeshObject(){

}

OpenGLESMeshObject::~OpenGLESMeshObject(){
    if(m_vertexArray){
        glDeleteVertexArrays(1, &m_vertexArray);
        m_vertexArray = NULL;
    }
    if(m_vertexBuffer){
        glDeleteBuffers(1, &m_vertexBuffer);
        m_vertexBuffer = NULL;
    }
    if(m_shader){
        delete m_shader;
        m_shader=nullptr;
    }
}

void OpenGLESMeshObject::prepare(){
    generateVertexs();
    prepareUniforms();
    prepareShaders();
}

void OpenGLESMeshObject::update(){
    updateUniforms();
    draw();
}

void OpenGLESMeshObject::setScreenPtr(uint32_t *pScreenWidth, uint32_t *pScreenHeight){
    m_pScreenWidth=pScreenWidth;
    m_pScreenHeight=pScreenHeight;
}

void OpenGLESMeshObject::generateVertexs(){

}

void OpenGLESMeshObject::prepareShaders(){

}

void OpenGLESMeshObject::prepareUniforms(){

}

void OpenGLESMeshObject::updateUniforms(){

}

void OpenGLESMeshObject::draw(){
    glBindVertexArray(m_vertexArray);
    glDrawArrays(GL_TRIANGLES, 0, m_indexCount);
}
END_NAMESPACE(OpenGLESTemplate)
