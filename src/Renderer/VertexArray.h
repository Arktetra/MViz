#pragma once

#include <glad/glad.h>

#include <iostream>

namespace MViz {
	class VA {
		unsigned int arrayID, bufferID, ibufferID;
	public:
		VA();
		VA(const void* data, int data_size);
		VA(const void * data, const void * indices, int data_size, int indices_size);
		unsigned int GetArrayID();
		unsigned int GetBufferID();
		void Bind();
		void Unbind();
		void Delete();
	};
}