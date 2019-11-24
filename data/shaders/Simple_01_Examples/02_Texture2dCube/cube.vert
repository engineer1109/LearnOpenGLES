#version 300 es

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;

uniform struct UBO{
    mat4 projection;
    mat4 model;
}ubo;

void main()
{
	gl_Position = ubo.projection*ubo.model* vec4(aPos, 1.0f);
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
