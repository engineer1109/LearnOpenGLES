#version 300 es
precision highp float;
out vec4 FragColor;

in vec2 TexCoord;
in float lodBias;
in vec3 normal;
in vec3 viewVec;
in vec3 lightVec;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
    vec4 color = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);

    vec3 N = normalize(normal);
    vec3 L = normalize(lightVec);
    vec3 V = normalize(viewVec);
    vec3 R = reflect(-L, N);
    vec3 diffuse = max(dot(N, L), 0.0) * vec3(1.0);
    float specular = pow(max(dot(R, V), 0.0), 16.0) * color.a;

    FragColor = vec4(diffuse * color.rgb + specular, 1.0);
}
