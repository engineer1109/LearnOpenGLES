#include "triangle.h"
int main(int argc,char** argv){
    Triangle* openglesPtr= new Triangle();
    openglesPtr->initWindow();
    openglesPtr->prepare();
    openglesPtr->renderLoop();
    return 1;
}
