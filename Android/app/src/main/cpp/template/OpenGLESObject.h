//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_OPENGLESOBJECT_H
#define LEARNOPENGLES_OPENGLESOBJECT_H

#include "base_template.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

interface OpenGLESObject {
public:
    OpenGLESObject() = default;
    ~OpenGLESObject() = default;

    virtual void prepare() = 0;
    virtual void update() = 0;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESOBJECT_H
