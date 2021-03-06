//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_OPENGLESUNIFORM_H
#define LEARNOPENGLES_OPENGLESUNIFORM_H

#include "OpenGLESObject.h"

#include <shader_m.h>

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESUniform : public OpenGLESObject {
public:
    OpenGLESUniform() = default;

    virtual ~OpenGLESUniform();

    virtual void prepare() override;

    virtual void update() override;

    virtual void prepareUniforms() = 0;

    virtual void updateUniforms() = 0;

    void setShaders(const std::vector<Shader *> &shaders) { m_shaders = shaders; }

    void updateSignal() { m_updateSignal = true; }

    void setAlwaysUpdate(const bool &value) { m_alwaysUpdate = value; }

protected:
    uint32_t m_uniformBuffer = NULL;
    bool m_updateSignal = false;
    bool m_alwaysUpdate = true;
    std::vector<Shader *> m_shaders;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESUNIFORM_H
