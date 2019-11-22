#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include "opengles_imgui.h"
ImguiOverlay::~ImguiOverlay(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
}

void ImguiOverlay::init(){
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();

    unsigned char* fontData;
    int texWidth, texHeight;

    io.DisplaySize=ImVec2((float)(1280), (float)(720));
    io.Fonts->AddFontFromFileTTF("./../data/Roboto-Medium.ttf", 16.0f);
    io.Fonts->GetTexDataAsRGBA32(&fontData, &texWidth, &texHeight);

    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_TitleBg] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.0f, 0.0f, 0.0f, 0.1f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(1.0f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.8f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(1.0f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.8f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 0.0f, 0.0f, 0.8f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.0f, 0.0f, 0.8f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.1f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(1.0f, 1.0f, 1.0f, 0.2f);
    style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 0.0f, 0.0f, 0.4f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 0.0f, 0.0f, 0.6f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 0.0f, 0.0f, 0.8f);
    // Dimensions

    io.FontGlobalScale = scale;
}

void ImguiOverlay::render(){
    bool ImGui = true;
    bool show_demo_window=true;

    ImGui::NewFrame();
    ImGui_ImplOpenGL3_NewFrame();                          // Create a window called "Hello, world!" and append into it.

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
    ImGui::SetNextWindowPos(ImVec2(10, 10));
    ImGui::SetNextWindowSize(ImVec2(30, 30), ImGuiCond_FirstUseEver);
    ImGui::Begin("LearnOpenGLES", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::Text("LearnOpenGLES      ");

    //ImGui::Text("%.2f ms/frame (%.1d fps)", (1000.0f / lastFPS), lastFPS);
    if (ImGui::Button("Button")){

    }

    ImGui::End();

    ImGui::PopStyleVar();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImguiOverlay::resize(uint32_t width, uint32_t height)
{
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)(width), (float)(height));
}

bool ImguiOverlay::header(const char *caption)
{
    return ImGui::CollapsingHeader(caption, ImGuiTreeNodeFlags_DefaultOpen);
}

bool ImguiOverlay::checkBox(const char *caption, bool *value)
{
    bool res = ImGui::Checkbox(caption, value);
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::checkBox(const char *caption, int32_t *value)
{
    bool val = (*value == 1);
    bool res = ImGui::Checkbox(caption, &val);
    *value = val;
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::inputFloat(const char *caption, float *value, float step, uint32_t precision)
{
    bool res = ImGui::InputFloat(caption, value, step, step * 10.0f, precision);
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::sliderFloat(const char* caption, float* value, float min, float max)
{
    bool res = ImGui::SliderFloat(caption, value, min, max);
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::sliderInt(const char* caption, int32_t* value, int32_t min, int32_t max)
{
    bool res = ImGui::SliderInt(caption, value, min, max);
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::comboBox(const char *caption, int32_t *itemindex, std::vector<std::string> items)
{
    if (items.empty()) {
        return false;
    }
    std::vector<const char*> charitems;
    charitems.reserve(items.size());
    for (size_t i = 0; i < items.size(); i++) {
        charitems.push_back(items[i].c_str());
    }
    uint32_t itemCount = static_cast<uint32_t>(charitems.size());
    bool res = ImGui::Combo(caption, itemindex, &charitems[0], itemCount, itemCount);
    if (res) { updated = true; };
    return res;
}

bool ImguiOverlay::button(const char *caption)
{
    bool res = ImGui::Button(caption);
    if (res) { updated = true; };
    return res;
}

void ImguiOverlay::text(const char *formatstr, ...)
{
    va_list args;
    va_start(args, formatstr);
    ImGui::TextV(formatstr, args);
    va_end(args);
}
