#pragma once

#include <glad/glad.h>

#include <iostream>
#include "../Utils/Utils.h"

namespace MViz {
	class VA {
		unsigned int arrayID, bufferID, ibufferID;
	public:
		VA();
		VA(const void* data, int data_size);												// for any type of shapes
		VA(const void * data, const void * indices, int data_size, int indices_size);		// for any type of shapes
		VA(std::array<Vertex, 6> vertices);													// for quads
		unsigned int GetArrayID();
		unsigned int GetBufferID();
		void Bind();
		void Unbind();
		void Delete();
	};
}