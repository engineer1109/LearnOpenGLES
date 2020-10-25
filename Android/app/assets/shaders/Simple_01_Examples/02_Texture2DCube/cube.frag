#version 300 es
precision highp float;
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
        //FragColor = vec4(vec3(pow(gl_FragCoord.z,150.f)), 1.0f);
        //gl_FragDepth=gl_FragCoord.z;
        //gl_FragDepth=gl_FragCoord.z/255.f;
}
