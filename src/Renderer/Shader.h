#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

namespace MViz {
	class Shader {
		bool IsOrtho = false;
		unsigned int programID;
		std::string path;
		std::string vsFile;
		std::string fsFile;
	public:
		Shader(std::string fpath, std::string verFile, std::string fragFile);
		unsigned int CompileShader(unsigned int type);
		unsigned int GetProgramID();
		std::string ParseShader(std::string shaderFile);
		void Use();
		void Orthogonalize(float width, float height);
		void CheckCompileError(unsigned int shaderID, unsigned int type);
		void CheckOrtho();
		void Delete();
	};
}