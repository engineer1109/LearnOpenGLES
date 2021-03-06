//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_TRIANGLEOBJECT_H
#define LEARNOPENGLES_TRIANGLEOBJECT_H

#include "OpenGLESMeshObject.h"

BEGIN_NAMESPACE(OpenGLESEngine)

class TriangleObject : public OpenGLESTemplate::OpenGLESMeshObject {
public:
    TriangleObject() = default;

    ~TriangleObject() = default;

    void generateVertexs() override;
};

END_NAMESPACE(OpenGLESEngine)

#endif //LEARNOPENGLES_TRIANGLEOBJECT_H
