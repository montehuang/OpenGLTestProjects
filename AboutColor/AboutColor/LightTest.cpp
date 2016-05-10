//#include<iostream>
//#include<cmath>
//
////GLEW
//#define GLEW_STATIC
//#include<GL/glew.h>
//
////GLFW
//#include<GLFW/glfw3.h>
//
//#include<SOIL/SOIL.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//
//#include"Shader.h"
//#include"TheCamera.h"
//
////function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void do_movement();
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//Camera camera(glm::vec3(1.0f, 1.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0;
//GLfloat lastY = HEIGHT / 2.0;
//bool keys[1024];
//
//glm::vec3 lightPos(1.0f, 1.5f, 1.0f);
//
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//	glfwInit();
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "ColorTest", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	glewExperimental = GL_TRUE;
//
//	glewInit();
//
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	glEnable(GL_DEPTH_TEST);
//
//	//Build and compile shader program
//	Shader lightingShader("../res/ambient_diffuse_specular_gouraud.vs", "../res/ambient_diffuse_specular_gouraud.frag");
//	Shader lampShader("../res/lamp.vs", "../res/lamp.frag");
//
//	// Set up vertex data (and buffer(s)) and attribute pointers
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
//
//		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
//
//		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
//		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
//		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
//		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
//
//		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
//		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
//		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
//		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
//		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
//
//		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
//		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
//		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
//		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f
//	};
//
//	GLuint VBO, containerVAO;
//	glGenVertexArrays(1, &containerVAO);
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(containerVAO);
//	// Position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	// Normal attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//
//	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//	GLuint lightVAO;
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	// Set the vertex attributes (only position data for the lamp))
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0); // Note that we skip over the normal vectors
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Calculate deltatime of current frame
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//		do_movement();
//
//		// Clear the colorbuffer
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
//		lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
//		// Use cooresponding shader when setting uniforms/drawing objects
//		lightingShader.Use();
//		GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
//		GLint lightColorLoc = glGetUniformLocation(lightingShader.Program, "lightColor");
//		GLint lightPosLoc = glGetUniformLocation(lightingShader.Program, "lightPos");
//		GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//		glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
//		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
//		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
//		glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
//
//
//
//		// Create camera transformations
//		glm::mat4 view;
//		view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(camera.Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		// Get the uniform locations
//		GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//		// Pass the matrices to the shader
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		// Draw the container (using container's vertex attributes)
//		glBindVertexArray(containerVAO);
//		glm::mat4 model;
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		// Also draw the lamp object, again binding the appropriate shader
//		lampShader.Use();
//		// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
//		modelLoc = glGetUniformLocation(lampShader.Program, "model");
//		viewLoc = glGetUniformLocation(lampShader.Program, "view");
//		projLoc = glGetUniformLocation(lampShader.Program, "projection");
//		// Set matrices
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		model = glm::mat4();
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		// Draw the light object (using light's vertex attributes)
//		glBindVertexArray(lightVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glfwTerminate();
//	return 0;
//}
//
////is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	if (key >= 0 && key < 1024)
//	{
//		if (action == GLFW_PRESS)
//			keys[key] = true;
//		else if (action == GLFW_RELEASE)
//			keys[key] = false;
//	}
//}
//
//void do_movement()
//{
//	if (keys[GLFW_KEY_W])
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (keys[GLFW_KEY_S])
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (keys[GLFW_KEY_A])
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (keys[GLFW_KEY_D])
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
//bool firstMouse = true;
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	GLfloat xoffset = xpos - lastX;
//	GLfloat yoffset = ypos - lastY;
//
//	lastX = xpos;
//	lastY = ypos;
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//
//
