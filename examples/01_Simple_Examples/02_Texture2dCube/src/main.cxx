#include "texture2dcube.h"
int main(int argc,char** argv){
    Texture2dCube* openglesPtr= new Texture2dCube();
    openglesPtr->initWindow();
    openglesPtr->prepare();
    openglesPtr->renderLoop();
    return 1;
}
