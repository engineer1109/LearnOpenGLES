#version 300 es
//#extension GL_ARB_separate_shader_objects : enable
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;
layout (location = 2) in vec3 aNormal;

out vec3 ourColor;

layout (std140) uniform UBO{
    mat4 projection;
    mat4 model;
    mat4 view;
    mat4 normal;
    vec4 lightPos;
}ubo;

void main()
{
    gl_Position = ubo.projection*ubo.model*vec4(aPos, 1.0);
    ourColor = aNormal;
}
