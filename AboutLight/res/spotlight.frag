#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;

struct Material {
	sampler2D diffuse;
	vec3 specular;
	float shininess;
};
struct Light {
	vec3 position;
	vec3 direction;
	float cutOff;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float constant;
	float linear;
	float quadratic;
};

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

vec3 getLightResult();
void main()
{
	vec3 lightDir = normalize(light.position - FragPos);
	float theta = dot(lightDir, normalize(-light.direction));
	if (theta > light.cutOff)
	{
		vec3 lightResult = getLightResult();
		color = vec4(lightResult, 1.0f);
	}
	else
	{
		color = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)), 1.0f);
	}
}
vec3 getLightResult()
{
	//attenuation value
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f / (light.constant +
						light.linear * distance +
						light.quadratic * (distance * distance));
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	
	//diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	
	//specular
	vec3 viewerDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewerDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * (spec * material.specular);
	
	//ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	vec3 result = ambient + diffuse + specular;
	return result;
}