#pragma once 

#include "glad/glad.h"


namespace MyEngine {


class Buffer {
public:
	Buffer() {
		glGenBuffers(1, &ID);
	}

	template <typename T, int N>
	void load(const T(&vertices)[N], const GLenum usage) {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, usage);
	}

	void bind() {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

private:
	unsigned int ID;
};


class ElementBuffer {
public:
	ElementBuffer() {
		glGenBuffers(1, &ID);
	}

	template <typename T, int N>
	void load(const T(&vertices)[N], const GLenum usage) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertices), vertices, usage);
	}

	void bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	void unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

private:
	unsigned int ID;
};



}