#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace MViz {
	class Window {
		GLFWwindow* window;
	public:
		Window(float width, float height, const char* title);
		GLFWwindow* GetWindow() {
			return window;
		}
	};
}
