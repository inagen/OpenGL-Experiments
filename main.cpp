#include <iostream>
#include "window.h"
#include "shader.h"

using namespace MyEngine;

int main() {
	Window window;
	window.create("Hello, Window!", 800, 600);

	while(window.isOpen()) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		window.swapBuffers();
	}

}