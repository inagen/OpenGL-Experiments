#include "window.h"
#include <string>
#include <sstream>
#include <iostream>

namespace MyEngine {

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}


void Window::create(std::string windowName, unsigned windowWidth, unsigned windowHeight) {	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);
	if(!m_window) {
		std::cout << "Failed to create window!" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    	std::cout << "Failed to initialize glad" << std::endl;
    	return;  
    }

	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);		
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

unsigned Window::getWindowWidth() {
	return m_windowWidth;
}

unsigned Window::getWindowHeight() {
	return m_windowHeight;
}

bool Window::isOpen() {
	return !glfwWindowShouldClose(m_window);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers() {
	glfwSwapBuffers(m_window);
}

void Window::pollEvents() {
	glfwPollEvents();
}

}

