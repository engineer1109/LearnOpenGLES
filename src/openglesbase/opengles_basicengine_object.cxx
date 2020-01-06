#include "opengles_basicengine_object.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
Object::Object(){

}

Object::~Object(){
    glDeleteVertexArrays(1, &m_vertexArray);
    glDeleteBuffers(1, &m_vertexBuffer);
    if(m_shader){
        delete m_shader;
        m_shader=nullptr;
    }
}

void Object::prepare(){
    generateVertexs();
    prepareUniforms();
    prepareShaders();
}

void Object::update(){
    updateUniforms();
}

void Object::setScreenPtr(uint32_t *pScreenWidth, uint32_t *pScreenHeight){
    m_pScreenWidth=pScreenWidth;
    m_pScreenHeight=pScreenHeight;
}

void Object::generateVertexs(){

}

void Object::prepareShaders(){

}

void Object::prepareUniforms(){

}

void Object::updateUniforms(){

}
END_NAMESPACE(OpenGLESTemplate)
