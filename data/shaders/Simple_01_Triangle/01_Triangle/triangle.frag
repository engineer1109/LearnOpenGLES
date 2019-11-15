#version 300 es
#extension GL_ARB_separate_shader_objects : enable
precision mediump float;
layout (location = 0) in vec3 ourColor;
layout (location = 0) out vec4 outFragColor;
void main()
{
    outFragColor = vec4(ourColor, 1.0f);
}
