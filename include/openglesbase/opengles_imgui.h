#ifndef OPENGLES_IMGUI_H
#define OPENGLES_IMGUI_H
#include <imgui.h>
#include <imgui_impl_opengl3.h>
class ImguiOverlay{
public:
    ImguiOverlay()=default;
    ~ImguiOverlay();

    void init();
    void render();
};
#endif // OPENGLES_IMGUI_H
