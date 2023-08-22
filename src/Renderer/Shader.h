#pragma once
#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

namespace MViz {
	class Shader {
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
		void CheckCompileError(unsigned int shaderID, unsigned int type);
		void Delete();
	};
}