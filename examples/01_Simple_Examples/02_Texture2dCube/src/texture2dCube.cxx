#include "shader_m.h"
#include "stb_image_aug.h"
#include "texture2dcube.h"
Texture2dCube::Texture2dCube(){
    zoom=-2;
    title="Texture 2d Examples";
}

Texture2dCube::~Texture2dCube(){
    glDeleteVertexArrays(1, &m_vertexArray);
    glDeleteBuffers(1, &m_vertexBuffer);
}

void Texture2dCube::prepare(){
    glEnable(GL_DEPTH_TEST);
    prepareBase();
    generateVertexs();
    prepareTextures();
    prepareShaders();
    prepareUniforms();
    prepared=true;
}

void Texture2dCube::render(){
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glViewport(0,0,uint32_t(width),uint32_t(height));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_texture2);
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    updateUniforms(true);
    startAutoRotation();
    glDrawArrays(GL_TRIANGLES, 0, 36);


    glFlush();
}

void Texture2dCube::OnUpdateUIOverlay(ImguiOverlay* overlay){
    if (overlay->header("Settings")) {
        if (overlay->button("Auto Rotation")) {
            m_autoRotation=!m_autoRotation;
        }
     }
}

void Texture2dCube::generateVertexs(){
    std::vector<Vertex> vertices =
    {

        { {  1.0f,  1.0f,  1.0f },{ 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
        { { -1.0f, -1.0f,  1.0f },{ 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } },
        { { -1.0f,  1.0f,  1.0f },{ 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
        { {  1.0f,  1.0f,  1.0f },{ 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
        { {  1.0f, -1.0f,  1.0f },{ 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } },
        { { -1.0f, -1.0f,  1.0f },{ 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } },

        { {  1.0f,  1.0f, -1.0f },{ 0.0f, 1.0f }, { 0.0f, 0.0f,-1.0f } },
        { { -1.0f,  1.0f, -1.0f },{ 1.0f, 1.0f }, { 0.0f, 0.0f,-1.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f }, { 0.0f, 0.0f,-1.0f } },
        { {  1.0f,  1.0f, -1.0f },{ 0.0f, 1.0f }, { 0.0f, 0.0f,-1.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f }, { 0.0f, 0.0f,-1.0f } },
        { {  1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f }, { 0.0f, 0.0f,-1.0f } },

        { {  1.0f,  1.0f,  1.0f },{ 0.0f, 1.0f }, { 1.0f, 0.0f, 0.0f } },
        { {  1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
        { {  1.0f, -1.0f,  1.0f },{ 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
        { {  1.0f,  1.0f,  1.0f },{ 0.0f, 1.0f }, { 1.0f, 0.0f, 0.0f } },
        { {  1.0f,  1.0f, -1.0f },{ 1.0f, 1.0f }, { 1.0f, 0.0f, 0.0f } },
        { {  1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },

        { { -1.0f,  1.0f,  1.0f },{ 1.0f, 1.0f }, {-1.0f, 0.0f, 0.0f } },
        { { -1.0f, -1.0f,  1.0f },{ 1.0f, 0.0f }, {-1.0f, 0.0f, 0.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f }, {-1.0f, 0.0f, 0.0f } },
        { { -1.0f,  1.0f,  1.0f },{ 1.0f, 1.0f }, {-1.0f, 0.0f, 0.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f }, {-1.0f, 0.0f, 0.0f } },
        { { -1.0f,  1.0f, -1.0f },{ 0.0f, 1.0f }, {-1.0f, 0.0f, 0.0f } },

        { {  1.0f,  1.0f,  1.0f },{ 1.0f, 0.0f }, { 0.0f, 1.0f, 0.0f } },
        { { -1.0f,  1.0f,  1.0f },{ 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f } },
        { { -1.0f,  1.0f, -1.0f },{ 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
        { {  1.0f,  1.0f,  1.0f },{ 1.0f, 0.0f }, { 0.0f, 1.0f, 0.0f } },
        { { -1.0f,  1.0f, -1.0f },{ 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
        { {  1.0f,  1.0f, -1.0f },{ 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },

        { {  1.0f, -1.0f,  1.0f },{ 1.0f, 1.0f }, { 0.0f,-1.0f, 0.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f }, { 0.0f,-1.0f, 0.0f } },
        { { -1.0f, -1.0f,  1.0f },{ 0.0f, 1.0f }, { 0.0f,-1.0f, 0.0f } },
        { {  1.0f, -1.0f,  1.0f },{ 1.0f, 1.0f }, { 0.0f,-1.0f, 0.0f } },
        { {  1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f }, { 0.0f,-1.0f, 0.0f } },
        { { -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f }, { 0.0f,-1.0f, 0.0f } },
    };

//    float vertices[] = {
//           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

//           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//           -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

//           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//           -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

//           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

//           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//           -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//       };

    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(m_vertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);  //unbind
}

void Texture2dCube::prepareTextures(){
    // texture 1
    // ---------
    glGenTextures(1, &m_texture1);
    glBindTexture(GL_TEXTURE_2D, m_texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../data/textures/container.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        std::cout<<nrChannels<<std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glGenTextures(1, &m_texture2);
    glBindTexture(GL_TEXTURE_2D, m_texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load("../data/textures/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        std::cout<<nrChannels<<std::endl;
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Texture2dCube::prepareShaders(){
    m_shader= new Shader(FS::getAssetPath("shaders/Simple_01_Examples/02_Texture2dCube/cube.vert").c_str(),
                     FS::getAssetPath("shaders/Simple_01_Examples/02_Texture2dCube/cube.frag").c_str());
    m_shader->use();
    m_shader->setInt("texture1", 0);
    m_shader->setInt("texture2", 1);
}

void Texture2dCube::prepareUniforms(){
    m_uboVS.projection = glm::perspective(glm::radians(60.f), float(width)/float(height), 0.001f, 256.0f);
    m_uboVS.model=glm::mat4(1.0);
    updateUniforms(true);
}

void Texture2dCube::updateUniforms(bool update){
    if(update){
        m_shader->setMat4("ubo.projection", m_uboVS.projection);
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, zoom));
        m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), cameraPos);
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
//        std::cout<<m_uboVS.model[0][0]<<" "<<m_uboVS.model[0][1]<<" "<<m_uboVS.model[0][2]<<" "<<m_uboVS.model[0][3]<<std::endl;
//        std::cout<<m_uboVS.model[1][0]<<" "<<m_uboVS.model[1][1]<<" "<<m_uboVS.model[1][2]<<" "<<m_uboVS.model[1][3]<<std::endl;
//        std::cout<<m_uboVS.model[2][0]<<" "<<m_uboVS.model[2][1]<<" "<<m_uboVS.model[2][2]<<" "<<m_uboVS.model[2][3]<<std::endl;
//        std::cout<<m_uboVS.model[3][0]<<" "<<m_uboVS.model[3][1]<<" "<<m_uboVS.model[3][2]<<" "<<m_uboVS.model[3][3]<<std::endl;
    }
    m_shader->setMat4("ubo.model", m_uboVS.model);
}

void Texture2dCube::startAutoRotation(){
    if(m_autoRotation){
        rotation.y++;
    }
}
