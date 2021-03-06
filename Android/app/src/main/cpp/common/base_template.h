//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_BASE_TEMPLATE_H
#define LEARNOPENGLES_BASE_TEMPLATE_H

#include "render_common.h"

BEGIN_NAMESPACE(OpenGLESEngine)

template<class T>
void delete_ptr(T* &ptr){
    if(ptr){
        delete ptr;
        ptr = nullptr;
    }
}

template<class T>
void delete_array(T* &ptr){
    if(ptr){
        delete[] ptr;
        ptr = nullptr;
    }
}

END_NAMESPACE(OpenGLESEngine)

#endif //LEARNOPENGLES_BASE_TEMPLATE_H
