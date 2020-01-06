#version 300 es

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;
out float lodBias;
out vec3 normal;
out vec3 viewVec;
out vec3 lightVec;

uniform struct UBO{
    mat4 projection;
    mat4 model;
    vec4 viewPos;
    float lodBias;
}ubo;

void main()
{
    gl_Position = ubo.projection*ubo.model* vec4(aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);

    vec4 pos = ubo.model * vec4(aPos, 1.0);
    normal=mat3(inverse(transpose(ubo.model))) * aNormal;
    vec3 lightPos = vec3(0.0);
    vec3 lPos = mat3(ubo.model) * lightPos.xyz;
    lightVec = lPos - pos.xyz;
    viewVec = ubo.viewPos.xyz - pos.xyz;
}
