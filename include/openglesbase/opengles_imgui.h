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
private:
    float scale=1.f;
};
#endif // OPENGLES_IMGUI_H
