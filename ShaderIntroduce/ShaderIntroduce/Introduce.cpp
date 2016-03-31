//#include<iostream>
//#define GLEW_STATIC
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//using namespace std;
//// Shaders
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"layout (location = 1) in vec3 color;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"ourColor = color;"
//"}\0";
//const GLchar* fragmentShaderSource = "#version 330 core\n"
//"in vec3 ourColor;"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(ourColor , 1.0f);\n"
//"}\n\0";
//const GLuint WIDTH = 800, HEIGHT = 600;
//int main()
//{
//	//get max number of vertex attributes
//	GLint nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//
//
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	glewInit();
//
//	// Define the viewport dimensions
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success){
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		cout << "error::shader::vertex::compilation_failed" << infoLog << endl;
//	}
//
//	//Fragment shader
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success){
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		cout << "error::shader::fragment::compilation_failed" << infoLog << endl;
//	}
//
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success){
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		cout << "error::shader::program::linking_failed" << infoLog << endl;
//	}
//
//	
//	//GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//	//glUseProgram(shaderProgram);
//	
//
//	GLfloat triangle[] = {
//		0.5f, 0.5f, 0.0f, 1.0f , 0.0f , 0.0f,
//		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//		0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
//	};
//
//	GLuint VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle,GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window)){
//		glfwPollEvents();
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		/*GLfloat timeValue = glfwGetTime();
//		GLfloat greenValue = (sin(timeValue));*/
//		
//		glUseProgram(shaderProgram);
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//
//	return 0;
//}