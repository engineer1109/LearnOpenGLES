#version 300 es
//#extension GL_ARB_separate_shader_objects : enable
precision mediump float;
in vec3 ourColor;
out vec4 outFragColor;
void main()
{
    outFragColor = vec4(ourColor, 1.0f);
}
