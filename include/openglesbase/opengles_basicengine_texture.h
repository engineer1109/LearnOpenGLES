#ifndef OPENGLES_BASICENGINE_TEXTURE_H
#define OPENGLES_BASICENGINE_TEXTURE_H
#include "opengles_basicengine_help.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Texture{
public:
    Texture()=default;
    ~Texture(){
        if(m_textureID){
            glDeleteTextures(1,&m_textureID);
        }
    }

    uint32_t getSize(){
        return m_size;
    }

    uint32_t getTextureID(){
        return m_textureID;
    }
protected:
    uint32_t m_textureID=0;
    uint32_t m_size=0;
};

class Texture2D:public Texture{
public:
    Texture2D()=default;
    ~Texture2D()=default;

    //If you turn off autoFree, you can use getImgPtr Later.But you need free manually.
    void loadFromFile(std::string file,
                      GLint format=GL_RGBA,
                      GLint addressMode=GL_REPEAT,
                      GLint filter=GL_LINEAR,
                      bool autoFree=true);

    void loadFromArray(uint8_t* data,uint32_t width,uint32_t height,uint32_t channels,
                       GLint format=GL_RGBA,
                       GLint addressMode=GL_REPEAT,
                       GLint filter=GL_LINEAR);

    uint32_t getWidth();
    uint32_t getHeight();
    uint32_t getChannels();
    uint32_t getSize();
    uint8_t* getImgPtr();

    //only for loadFromFile when turning off autoFree
    void freeImgPtr();
protected:
    uint32_t m_width=0;
    uint32_t m_height=0;
    uint32_t m_channels=0;
    uint8_t* m_data=nullptr;
};
END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_TEXTURE_H
