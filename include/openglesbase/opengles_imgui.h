#ifndef OPENGLES_IMGUI_H
#define OPENGLES_IMGUI_H
#include <vector>
#include <string>
#include <stdint.h>
#include "openglesbase_export.h"
class OPENGLESBASE_EXPORT ImguiOverlay{
public:
    ImguiOverlay()=default;
    ~ImguiOverlay();

    void init();
    void render();

    void resize(uint32_t width, uint32_t height);
    bool header(const char *caption);
    bool checkBox(const char *caption, bool *value);
    bool checkBox(const char *caption, int32_t *value);
    bool inputFloat(const char *caption, float *value, float step, uint32_t precision);
    bool sliderFloat(const char* caption, float* value, float min, float max);
    bool sliderInt(const char* caption, int32_t* value, int32_t min, int32_t max);
    bool comboBox(const char *caption, int32_t *itemindex, std::vector<std::string> items);
    bool button(const char *caption);
    void text(const char *formatstr, ...);
private:
    float scale=1.f;
    bool visible = true;
    bool updated = false;
};
#endif // OPENGLES_IMGUI_H
