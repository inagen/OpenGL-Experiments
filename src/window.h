#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>

namespace MyEngine {

class Window {
public:
	void create(std::string windowName, unsigned windowWidth, unsigned windowHeight);
	unsigned getWindowWidth();
	unsigned getWindowHeight();
	bool isOpen();
	void clear();
	void swapBuffers();
	void pollEvents();

	GLFWwindow* m_window;
private:
	
	unsigned m_windowWidth;
	unsigned m_windowHeight;
};

}

