//
// Created by wjl on 21-2-7.
//

#ifndef OPENGLESDEMO_VOLUMECLOUD_H
#define OPENGLESDEMO_VOLUMECLOUD_H

#include "OpenGLESBase.h"
#include "vertex_struct.h"

BEGIN_NAMESPACE(OpenGLESEngine)

class VolumeCloud : public OpenGLESBase  {
public:
    VolumeCloud();
    ~VolumeCloud();

    void prepare();

    void update();

};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESDEMO_VOLUMECLOUD_H
