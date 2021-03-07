# LearnOpenGLES
This project is mainly based on the code of [LearnOpenGL](https://github.com/JoeyDeVries/LearnOpenGL) and adopted some cross-platform features of [Vulkan](https://github.com/SaschaWillems/Vulkan.git).  
All rendering code is front-end and back-end separated. The gui or window is running on the front-end, and the opengles render is running on the backend. The front-end code is only for presentation, and the back-end OpenGLES is only for rendering computation regardless of the GUI. You can choose the display surface you like, such as GLFW3, xcb(X11), WIN32UI, and Qt. You just need to create a native window Handle (such as HWND and xcb_window_t), and give the window handle to the EGL to create a rendering surface. It is easily integrated into any front-end framework, and this project shows the examples of Qt (not using QOpengGLWidget).  
# Requirements
## Supported System:
   **Now:** Linux(Mainly)  Android(Mainly)   Windows(Partly)
   **Planned supported:** Mac IOS
## Libraries and Tools
   **CMake:** 3.14+ is recommended 
   **OpenGLES:** 3.0+
   **Glm:** 0.9.9+
   **Xcb & Xlib**    (Linux needs)
   **GLFW3**         
   **OpenCV:** 4.0+  (Some projects need)
   **CUDA:** 10.0+  (Some projects need)
   **Qt:** 5.12+  (Some projects need)
# Compile & BUILD
## For Linux/UNIX
If you don't have GLM, GLI, IMGUI, you need "git submodule update --init" first.
```
   git submodule update --init
```
   Compile
```
    cmake ..
    make
    make install
```
The programs will be installed in the {PROJECT_DIR}/bin .
## For Android
Use Android Studio to open the directory (./Android)
Default ndk version 21.1.6352462
Android Sdk version 30
### For Qt
```
    cmake .. -DBUILD_QtExamples=ON
```
## For Windows
   Compile
```
    cmake -G "Visual Studio 15 2017 Win64" -T host=x64 ..
    cmake --build . --config Release
    cmake --build . --config Release --target INSTALL
```
The programs will be installed in the {PROJECT_DIR}/Release .
# PLANS
1. Simple Examples (10%) (Only need OpenGLES)
