#include <iostream>
#include "triangle.h"
void Triangle::render(){
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    if(mouseWheel.up){
        std::cout<<"up"<<std::endl;
    }
}

void Triangle::keyPressed(uint32_t value){
    std::cout<<value<<std::endl;
}

void Triangle::mouseMoved(double x, double y, bool & handled){
    //std::cout<<x<<std::endl;
    if(mouseButtons.left){
        std::cout<<"click"<<std::endl;
    }
    if(mouseWheel.up){
        std::cout<<"up"<<std::endl;
    }
}
