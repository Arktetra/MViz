#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>

#include <iostream>

namespace MViz {
	class Window {
		GLFWwindow* window;
		int width;
		int height;
	public:
		Window(float width, float height, const char* title);
		GLFWwindow* GetWindow();
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void GetMousePos();
	};
	bool IsMouseClicked(void);
	std::array<int, 2> GetClickPos();
}
