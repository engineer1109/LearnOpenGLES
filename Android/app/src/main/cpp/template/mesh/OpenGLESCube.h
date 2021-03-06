//
// Created by wjl on 21-1-26.
//

#ifndef OPENGLESDEMO_OPENGLESCUBE_H
#define OPENGLESDEMO_OPENGLESCUBE_H

#include "OpenGLESMeshObject.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESCube : public OpenGLESMeshObject {
public:
    OpenGLESCube();
    virtual ~OpenGLESCube();

    void setSize(float a, float b, float c);

    virtual void generateVertexs() override;

protected:
    float m_a = 1.f;
    float m_b = 1.f;
    float m_c = 1.f;
};

END_NAMESPACE(OpenGLESTemplate)


#endif //OPENGLESDEMO_OPENGLESCUBE_H
