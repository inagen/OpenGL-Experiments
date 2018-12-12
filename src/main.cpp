#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include "window.h"
#include "shader.h"
#include "buffer.h"
#include "array.h"
#include "vector2.h"


using namespace MyEngine;

void processInput(GLFWwindow* window,float opacity) {

}

int main() {
	Window window;
	window.create("Hello, Triangle!", 700, 700);
	Shader shader("../shaders/shader.vs", "../shaders/shader.fs");
	shader.use();

	float vertices[] {
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,						
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f
	};

	unsigned int indices[] {
		0, 1, 3,
		1, 2, 3
	};

	int width, height, nrChannels;
	unsigned char* data = stbi_load("../Textures/anime.jpg", &width, &height, &nrChannels, 0); 

	int width2, height2, nrChannels2;
	unsigned char* data2 = stbi_load("../Textures/wall.jpg", &width2, &height2, &nrChannels2, 0); 

	unsigned int texture1;
	unsigned int texture2;

	glGenTextures(1, &texture1);
	glGenTextures(1, &texture2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);


	
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data2);


	VertexArray VAO;
	VAO.bind();

	Buffer VBO;
	VBO.load(vertices, GL_STATIC_DRAW);

	ElementBuffer EBO;
	EBO.load(indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);

	shader.setInt("ourTexture1", 0);
	shader.setInt("ourTexture2", 1);

	shader.setFloat("kek", 0.5f);
	float kek = 0.5f;

	while(window.isOpen()) {
		window.clear();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		if(glfwGetKey(window.m_window, GLFW_KEY_UP) == GLFW_PRESS && kek < 1.0) {
			kek += 0.01;
		} 
		if(glfwGetKey(window.m_window, GLFW_KEY_DOWN) == GLFW_PRESS && kek > 0.0) {
			kek -= 0.01;
		}

		shader.setFloat("kek", kek);
		window.pollEvents();
		window.swapBuffers();
	}

}