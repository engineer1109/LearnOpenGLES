#version 300 es

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;
out float lodBias;
out vec3 normal;
out vec3 viewVec;
out vec3 lightVec;

layout (std140) uniform UBO{
    mat4 projection;
    mat4 model;
    mat4 view;
    mat4 normal;
    vec4 lightPos;
}ubo;

void main()
{
    mat4 modelView = ubo.view * ubo.model;
    gl_Position = ubo.projection * modelView * vec4(aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);

    vec4 pos = modelView * vec4(aPos, 1.0);
    normal=mat3(inverse(transpose(modelView))) * aNormal;
    vec3 lightPos = vec3(0.0, 0.0, 0.0);
    vec3 lPos = mat3(modelView) * lightPos.xyz;
    lightVec = lPos - pos.xyz;
    vec3 viewPos = vec3(0.0);
    viewVec = viewPos - pos.xyz;
}
