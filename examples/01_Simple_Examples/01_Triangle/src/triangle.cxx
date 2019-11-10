#include <iostream>
#include "triangle.h"
void Triangle::render(){
    std::cout<<"1"<<std::endl;
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
