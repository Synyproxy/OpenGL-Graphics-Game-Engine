#version 330 core

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

out vec4 color;

uniform sampler2D texture_diffuse;
//uniform vec3 lightPos;
//uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{

  vec3 lightPos = vec3(0, 15, 0);
  vec3 lightColor = vec3(1, 1, 1);


  //Ambient Light
  float ambientStrength = 0.4f;
  vec3 ambient = ambientStrength * lightColor;

  //Diffuse Light
  vec3 norm = normalize(Normal);
  vec3 lightDir = normalize(lightPos - FragPos);

  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;

  //Specular Light
  float specularStrength = 0.5f ;
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = specularStrength * spec * lightColor;

  vec3 texture_diff = vec3( texture( texture_diffuse, TexCoords ));
  vec3 result = (ambient + diffuse + specular) * texture_diff;

  color = vec4(result, 1.0f);

  //color = vec4( texture( texture_diffuse, TexCoords ));
}
