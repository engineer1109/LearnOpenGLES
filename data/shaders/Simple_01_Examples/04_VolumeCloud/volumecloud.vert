#version 300 es

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inUVW;
layout (location = 2) in vec3 inNormal;

uniform struct UBO{
    mat4 projection;
    mat4 model;
    vec4 viewPos;
    float lodBias;
}ubo;

uniform struct ModelView 
{
    mat4 model;
} volumeModel;

out vec3 UVW;
out mat4 VolumeModel;

void main() 
{
    UVW = vec3(inUVW);
    VolumeModel=volumeModel.model;
    gl_Position = ubo.projection * ubo.model * vec4(inPos.xyz, 1.0);		
}
