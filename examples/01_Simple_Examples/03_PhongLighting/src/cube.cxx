#include "opengles_basicengine_filesystem.h"
#include "cube.h"
Cube::Cube(){

}

Cube::~Cube(){

}

void Cube::prepare(){
    generateVertexs();
    prepareTextures();
    prepareShaders();
    prepareUniforms();
}

void Cube::update(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureA.getTextureID());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_textureB.getTextureID());
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    updateUniforms();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::prepareTextures(){
    m_textureA.loadFromFile("../data/textures/container.png");
    m_textureB.loadFromFile("../data/textures/awesomeface.png");
}

void Cube::prepareShaders(){
    m_shader= new Shader(FS::getAssetPath("shaders/Simple_01_Examples/03_PhongLighting/cube.vert").c_str(),
                     FS::getAssetPath("shaders/Simple_01_Examples/03_PhongLighting/cube.frag").c_str());
    m_shader->use();
    m_shader->setInt("texture1", 0);
    m_shader->setInt("texture2", 1);
}

void Cube::prepareUniforms(){
    if(!m_pScreenWidth or !m_pScreenHeight){
        std::cerr<<"nullptr for m_pScreenWidth and m_pScreenHeight"<<std::endl;
    }
    m_uboVS.projection = glm::perspective(glm::radians(60.f), float(*m_pScreenWidth)/float(*m_pScreenHeight), 0.001f, 256.0f);
    m_uboVS.model=glm::mat4(1.0);
    m_uboVS.lodBias=0.f;
    updateUniforms();
}

void Cube::updateUniforms(){
    if(1){
        m_shader->setMat4("ubo.projection", m_uboVS.projection);
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, *m_camera.pZoom));
        m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), *m_camera.pCameraPos);
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians((*m_camera.pRotation).x), glm::vec3(1.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians((*m_camera.pRotation).y), glm::vec3(0.0f, 1.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians((*m_camera.pRotation).z), glm::vec3(0.0f, 0.0f, 1.0f));
        m_uboVS.viewPos = glm::vec4(0.0f, 0.0f, -*m_camera.pZoom, 0.0f);
    }
    m_shader->setMat4("ubo.model", m_uboVS.model);
}
