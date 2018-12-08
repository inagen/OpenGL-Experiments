#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "window.h"
#include "shader.h"

using namespace MyEngine;

int main() {
	Window window;
	window.create("Hello, Window!", 800, 600);
	Shader shader("../shaders/shader.vs", "../shaders/shader.fs");
	shader.use();

	float vertices[] {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO);

	while(
		window.isOpen()) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		window.swapBuffers();
	}

}