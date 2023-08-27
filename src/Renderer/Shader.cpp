#include "Shader.h"

namespace MViz {
	Shader::Shader(std::string fpath, std::string verFile, std::string fragFile) {
		path = fpath;
		vsFile = verFile;
		fsFile = fragFile;
		programID = glCreateProgram();
		
		unsigned int vs = CompileShader(GL_VERTEX_SHADER);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER);

		glAttachShader(programID, vs);
		glAttachShader(programID, fs);
		glLinkProgram(programID);
		glValidateProgram(programID);

		glDeleteProgram(vs);
		glDeleteProgram(fs);
	}

		unsigned int Shader::CompileShader(unsigned int type) {
		unsigned int shaderID = glCreateShader(type);

		std::string s = (type == GL_VERTEX_SHADER) ? ParseShader(vsFile) : ParseShader(fsFile);

		const char* source = s.c_str();
		std::cout << source;
		glShaderSource(shaderID, 1, &source, NULL);
		glCompileShader(shaderID);

		CheckCompileError(shaderID, type);

		return shaderID;
	}

	std::string Shader::ParseShader(std::string shaderFile) {
		std::ifstream source;
		std::string line;
		std::stringstream s;

		source.open(path + shaderFile);
		while (getline(source, line)) {
			s << line << "\n";
		}
		source.close();

		return s.str();
	}

	unsigned int Shader::GetProgramID() {
		return programID;
	}

	void Shader::CheckCompileError(unsigned int shaderID, unsigned int type) {
		int result;
		char infolog[512];

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE) {
			glGetShaderInfoLog(shaderID, 512, NULL, infolog);
			std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infolog << std::endl;
		}
	}

	void Shader::Use() {
		glUseProgram(programID);
	}

	void Shader::Orthogonalize(float width, float height) {
		IsOrtho = true;
		glm::mat4 projection = glm::ortho(0.0f, width, 0.0f, height);
		Use();
		glUniformMatrix4fv(glGetUniformLocation(GetProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	}

	void Shader::CheckOrtho() {
		if (!IsOrtho) {
			std::cout << "SHADER::ERROR::Unorthogonalized!" << std::endl;
			abort();
		}
	}

	void Shader::Delete() {
		glDeleteProgram(programID);
	}
}
