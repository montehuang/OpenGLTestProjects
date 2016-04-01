#ifndef SHADER_H_
#define SHADER_H_

#include<string.h>
#include<fstream>
#include<sstream>
#include<iostream>

#include <GL/glew.h>

class Shader
{
public:
	GLuint Program;

	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	GLfloat getProgram(){ return Program; }
	void Use();
private:
	void compileShaders(const GLchar* vertexCode, const GLchar* fragmentCode);
};
#endif