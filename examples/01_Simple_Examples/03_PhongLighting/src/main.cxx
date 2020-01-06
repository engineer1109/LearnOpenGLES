#include "phonglighting.h"
int main(int argc,char** argv){
    PhongLighting* openglesPtr= new PhongLighting();
    openglesPtr->initWindow();
    openglesPtr->prepare();
    openglesPtr->renderLoop();
    return 1;
}
