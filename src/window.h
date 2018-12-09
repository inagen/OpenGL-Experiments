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
private:
	GLFWwindow* m_window;
	unsigned m_windowWidth;
	unsigned m_windowHeight;
};

}

