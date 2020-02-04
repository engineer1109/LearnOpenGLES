#include "volumecloud.h"
int main(int argc, char **argv) {
    VolumeCloud *openglesPtr = new VolumeCloud();
    openglesPtr->initWindow();
    openglesPtr->prepare();
    openglesPtr->renderLoop();
    return 1;
}
