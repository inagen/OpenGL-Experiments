#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "window.h"
#include "shader.h"
#include "buffer.h"
#include "array.h"
#include "vector2.h"


using namespace MyEngine;

int main() {
	Window window;
	window.create("Hello, Triangle!", 800, 600);
	Shader shader("../shaders/shader.vs", "../shaders/shader.fs");
	shader.use();

	float vertices[] {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	VertexArray VAO;
	VAO.bind();

	Buffer VBO;
	VBO.load(vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);


	while(window.isOpen()) {
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		window.pollEvents();
		window.swapBuffers();
	}

}