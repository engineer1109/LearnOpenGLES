//
// Created by wjl on 21-1-27.
//

#include "PhongLightingCube.h"

#include <glm/gtc/matrix_transform.hpp>
#include <AssetReader.h>
#include <stb_image_aug.h>

PhongLightingCube::PhongLightingCube() : OpenGLESTemplate::OpenGLESCube() {

}

PhongLightingCube::~PhongLightingCube(){
    glDeleteTextures(1, &m_texture1);
    glDeleteTextures(1, &m_texture2);
}

void PhongLightingCube::prepare() {
    generateVertexs();
    prepareShaders();
    prepareUniforms();
    prepareTextures();
}

void PhongLightingCube::update() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_texture2);
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    //updateUniforms(true);
    updateUniforms();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void PhongLightingCube::prepareShaders() {
    m_shader = new Shader("shaders/Simple_01_Examples/03_PhongLighting/cube.vert",
                          "shaders/Simple_01_Examples/03_PhongLighting/cube.frag", m_asset);
    m_shader->use();
    m_shader->setInt("texture1", 0);
    m_shader->setInt("texture2", 1);
}

void PhongLightingCube::prepareUniforms() {
    m_uboVS.projection = glm::perspective(glm::radians(60.f), float(*m_pScreenWidth) / float(*m_pScreenHeight),
                                          0.001f, 256.0f);
    m_uboVS.model = glm::mat4(1.0);
    updateUniforms();
}

void PhongLightingCube::updateUniforms() {
    if (true) {
        m_shader->setMat4("ubo.projection", m_uboVS.projection);
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, *m_zoom));
        m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), *m_cameraPos);
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(m_rotation->x),
                                    glm::vec3(1.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(m_rotation->y),
                                    glm::vec3(0.0f, 1.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(m_rotation->z),
                                    glm::vec3(0.0f, 0.0f, 1.0f));
        // LOGI("%f",m_zoom);
    }
    m_shader->setMat4("ubo.model", m_uboVS.model);
}

void PhongLightingCube::prepareTextures() {
    // texture 1
    // ---------
    glGenTextures(1, &m_texture1);
    glBindTexture(GL_TEXTURE_2D, m_texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;

    AssetReader *assetReader = new AssetReader("textures/container.png", m_asset);
    assetReader->run();

    unsigned char *data = stbi_load_from_memory((uint8_t*)assetReader->getOutData(),assetReader->getSize(), &width, &height, &nrChannels, 0);
    if (data or assetReader->getSize()==0) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        LOGI("Failed Load Texture1");
    }
    stbi_image_free(data);
    delete assetReader;

    glGenTextures(1, &m_texture2);
    glBindTexture(GL_TEXTURE_2D, m_texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps

    AssetReader *assetReader2 = new AssetReader("textures/awesomeface.png", m_asset);
    assetReader2->run();
    data = stbi_load_from_memory((uint8_t*)assetReader2->getOutData(),assetReader2->getSize(), &width, &height, &nrChannels, 0);
    if (data or assetReader2->getSize() ==0) {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        LOGI("Failed Load Texture2");
    }
    delete assetReader2;
    stbi_image_free(data);
}
