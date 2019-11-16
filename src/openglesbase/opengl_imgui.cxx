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
}

void ImguiOverlay::render(){
    bool ImGui = true;
    bool show_demo_window=true;

    ImGui::NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");

    if (ImGui::Button("Button")){

    }

    ImGui::End();


    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
