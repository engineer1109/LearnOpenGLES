//
// Created by wjl on 21-3-6.
//

#include "UniformCamera.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

void UniformCamera::prepareUniforms() {
    m_cameraMat.projection = glm::perspective(glm::radians(60.f), float(*m_pScreenWidth) / float(*m_pScreenHeight),
                                              0.001f, 256.0f);
    m_cameraMat.view = glm::mat4(1.0);
    m_cameraMat.model = glm::mat4(1.0);
    m_cameraMat.normal = glm::mat4(1.0);
    m_cameraMat.lightpos = glm::vec4(0.f);

    for(auto shader : m_shaders){
        LOGI("shader %d", shader->ID);
        GLuint shaderIndex = glGetUniformBlockIndex(shader->ID, "UBO");
        LOGI("shaderIndex %d", shaderIndex);
        glUniformBlockBinding(shader->ID, shaderIndex, 0);
    }

    glGenBuffers(1, &m_uniformBuffer);
    glBindBuffer(GL_UNIFORM_BUFFER, m_uniformBuffer);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(CameraMatrix), nullptr, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, NULL);

    glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_uniformBuffer);
    //glBindBufferRange(GL_UNIFORM_BUFFER, 0, m_uniformBuffer, 0, sizeof(CameraMatrix));

    updateUniforms();
}

void UniformCamera::updateUniforms() {
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, *m_pZoom));
    m_cameraMat.view = viewMatrix * glm::translate(glm::mat4(1.0f), *m_pCameraPos);
    m_cameraMat.model = glm::mat4(1.f);
    m_cameraMat.model = glm::rotate(m_cameraMat.model, glm::radians(m_pRotation->x),
                                glm::vec3(1.0f, 0.0f, 0.0f));
    m_cameraMat.model = glm::rotate(m_cameraMat.model, glm::radians(m_pRotation->y),
                                glm::vec3(0.0f, 1.0f, 0.0f));
    m_cameraMat.model = glm::rotate(m_cameraMat.model, glm::radians(m_pRotation->z),
                                glm::vec3(0.0f, 0.0f, 1.0f));

    glBindBuffer(GL_UNIFORM_BUFFER, m_uniformBuffer);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(CameraMatrix), &m_cameraMat, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, NULL);
}

END_NAMESPACE(OpenGLESTemplate)
