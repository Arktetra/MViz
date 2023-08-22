#include <glad/glad.h>
#include"../includes/GLFW/glfw3.h"

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

#define ASSERT(x) if(!(x)) __debugbreak()
#define glCall(x) glClearError();\
x;\
ASSERT(glLogError(#x, __FILE__, __LINE__))

static void glClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool glLogError(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::string errorlog;
		switch (error)
		{
		case GL_INVALID_ENUM:					errorlog = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:					errorlog = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:				errorlog = "INVALID_OPERATION"; break;
		case GL_OUT_OF_MEMORY:					errorlog = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:	errorlog = "INVALID_FRAMEBUFFER_OPERATION"; break;
		default:								errorlog = "UNKNOWN_ERROR"; break;
		}																					  
		std::cout << "[OpenGl error]" << " (" << errorlog << ")" << " Line:" << line << std::endl;
		return false;
	}
	return true;
}

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSource parseShader(const char* filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << "\n";
		}
	}
	return { ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	int result;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;

	}

	return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(800, 600, "App", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	float vertices[] = {
		0.5f, -0.5f, 0.0f, 		//0
		-0.5f, -0.5f, 0.0f,		//1
		0.0f, 0.5f, 0.0f,		//2
		-1.0f, 0.5f, 0.0f		//3
	};

	unsigned int indices[] = {
		0, 1, 2,
		1, 2, 3
	};

	unsigned int buffer, array;
	glGenVertexArrays(1, &array);
	glGenBuffers(1, &buffer);
	glBindVertexArray(array);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	//glBindVertexArray(ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	const char* filepath = "res\\shaders\\basic.shader";
	ShaderProgramSource source = parseShader(filepath);
	std::cout << "VERTEX" << std::endl;
	std::cout << source.VertexSource << std::endl;
	std::cout << "FRAGMENT" << std::endl;
	std::cout << source.FragmentSource << std::endl;

	unsigned int shader = createShader(source.VertexSource, source.FragmentSource);

	glUseProgram(shader);

	glEnable(GL_PROGRAM_POINT_SIZE);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(array);
		glPointSize(10.0f);
		//glDrawArrays(GL_POINTS, 0, 4);
		glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0));
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &array);
	glDeleteBuffers(1, &buffer);
	glDeleteProgram(shader);

	glfwTerminate();

	return 0;

}