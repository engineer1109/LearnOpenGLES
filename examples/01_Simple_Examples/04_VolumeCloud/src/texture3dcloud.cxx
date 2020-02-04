#include "opengles_basicengine_algorithm.h"
#include "opengles_basicengine_algorithm_graphics.h"
#include "opengles_basicengine_filesystem.h"

#include "texture3dcloud.h"
Texture3DCloud::Texture3DCloud(uint32_t width, uint32_t height, uint32_t depth) {
    m_width = width;
    m_height = height;
    m_depth = depth;
    m_imgData = new uint8_t[width * height * depth];
}

Texture3DCloud::~Texture3DCloud() {
    if (m_imgData) {
        delete[] m_imgData;
        m_imgData = nullptr;
    }
}

void Texture3DCloud::prepare() {
    generateVertexs();
    prepareTextures();
    prepareShaders();
    prepareUniforms();
}

void Texture3DCloud::update() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, m_texture.getTextureID());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_pseudoColor.getTextureID());
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    updateUniforms();
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Texture3DCloud::prepareTextures() {
    OpenGLESTemplate::PerlinNoise<float> perlinNoise;
    OpenGLESTemplate::FractalNoise<float> fractalNoise(perlinNoise);

    const int32_t noiseType = rand() % 2;
    const float noiseScale = static_cast<float>(rand() % 10) + 4.0f;

#pragma omp parallel for num_threads(8)
    for (int32_t z = 0; z < m_width; z++) {
        for (uint32_t y = 0; y < m_height; y++) {
            for (int32_t x = 0; x < m_depth; x++) {
                float nx = (float)x / (float)m_width;
                float ny = (float)y / (float)m_height;
                float nz = (float)z / (float)m_depth;
#define FRACTAL
#ifdef FRACTAL
                float n = fractalNoise.noise(nx * noiseScale, ny * noiseScale, nz * noiseScale);
#else
                float n = 20.0 * perlinNoise.noise(nx, ny, nz);
#endif
                n = n - floor(n);

                m_imgData[x + y * m_width + z * m_height * m_depth] = static_cast<uint8_t>(floor(n * 255));
            }
        }
    }
    m_texture.loadFromArray(m_imgData, m_width, m_height, m_depth, 1, GL_R8, GL_CLAMP_TO_EDGE, GL_LINEAR);

    std::vector<glm::vec4> sampleColorList = {
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        //{  0.2, 0.2, 0.2, 1.0, },
        {
            0.8,
            0.8,
            0.8,
            1.0,
        },
        {
            1.0,
            1.0,
            1.0,
            1.0,
        },
        {
            0.8,
            0.8,
            0.8,
            1.0,
        },
        //{  0.2, 0.2, 0.2, 1.0, },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
        {
            0.0,
            0.0,
            0.0,
            0.0,
        },
    };
    std::vector<uint8_t> transferImg(sampleColorList.size() * 4);
    for (size_t i = 0; i < transferImg.size() / 4; i++) {
        transferImg[i * 4] = uint8_t(sampleColorList[i].x * 255);
        transferImg[i * 4 + 1] = uint8_t(sampleColorList[i].y * 255);
        transferImg[i * 4 + 2] = uint8_t(sampleColorList[i].z * 255);
        transferImg[i * 4 + 3] = uint8_t(sampleColorList[i].w * 255);
    }
    m_pseudoColor.loadFromArray(transferImg.data(), sampleColorList.size(), 1, 4, GL_RGBA, GL_CLAMP_TO_EDGE);
}

void Texture3DCloud::prepareShaders() {
    m_shader = new Shader(FS::getAssetPath("shaders/Simple_01_Examples/04_VolumeCloud/volumecloud.vert").c_str(),
                          FS::getAssetPath("shaders/Simple_01_Examples/04_VolumeCloud/volumecloud.frag").c_str());
    m_shader->use();
    m_shader->setInt("volumeData", 0);
    m_shader->setInt("pseudoColor", 1);
}

void Texture3DCloud::prepareUniforms() {
    if (!m_pScreenWidth or !m_pScreenHeight) {
        std::cerr << "nullptr for m_pScreenWidth and m_pScreenHeight" << std::endl;
    }
    m_uboVS.projection =
        glm::perspective(glm::radians(60.f), float(*m_pScreenWidth) / float(*m_pScreenHeight), 0.000f, 256.0f);
    m_uboVS.model = glm::mat4(1.0);
    m_uboVS.lodBias = 0.f;

    float m_ModelView[16] = {
        1.0f, 0.0f, 0.0f, 0.0f, //
        0.0f, 1.0f, 0.0f, 0.0f, //
        0.0f, 0.0f, 1.0f, 0.0f, //
        0.0f, 0.0f, 4.0f, 1.0f, //
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m_viewMat[i][j] = m_ModelView[4 * i + j];
        }
    }

    updateUniforms();
}

void Texture3DCloud::updateUniforms() {
    if (1) {
        m_shader->setMat4("ubo.projection", m_uboVS.projection);

        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, -sqrtf(3) / 2.f));
        m_uboVS.model = viewMatrix * glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(0.f), glm::vec3(1.0f, 0.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f));
        m_uboVS.model = glm::rotate(m_uboVS.model, glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
        m_uboVS.viewPos = glm::vec4(0.0f, 0.0f, -sqrtf(3) / 2.f, 0.0f);
    }
    m_shader->setMat4("ubo.model", m_uboVS.model);

    m_modelVolume.model = glm::mat4(1.f);
    m_modelVolume.model =
        OpenGLESTemplate::VolumeGLM::translate(m_modelVolume.model, glm::vec3(0.0f, 0.0f, *m_camera.zoom));
    m_modelVolume.model = OpenGLESTemplate::VolumeGLM::rotate(m_modelVolume.model, glm::radians(m_camera.rotation->x),
                                                              glm::vec3(1.0f, 0.0f, 0.0f));
    m_modelVolume.model = OpenGLESTemplate::VolumeGLM::rotate(m_modelVolume.model, glm::radians(m_camera.rotation->y),
                                                              glm::vec3(0.0f, 1.0f, 0.0f));
    m_modelVolume.model = OpenGLESTemplate::VolumeGLM::rotate(m_modelVolume.model, glm::radians(m_camera.rotation->z),
                                                              glm::vec3(0.0f, 0.0f, 1.0f));
    m_shader->setMat4("volumeModel.model", m_modelVolume.model);
}
