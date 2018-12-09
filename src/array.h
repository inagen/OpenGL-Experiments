#pragma once 

#include "glad/glad.h"


namespace MyEngine {

class VertexArray {
public:
	VertexArray() { glGenVertexArrays(1, &ID); }
	void bind() { glBindVertexArray(ID); }
	void unbind() { glBindVertexArray(0); }
private:
	unsigned int ID;
};


}