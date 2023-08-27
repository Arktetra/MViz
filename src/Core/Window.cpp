#include <Core/Window.h>

namespace MViz {

	static double mxpos, mypos;
	static double cxpos = 0, cypos = 0;
	static bool isclicked = false;
	static int btn, act;

	Window::Window(float width, float height, const char * title) {
		this->width = width;
		this->height = height;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (!glfwInit()) { abort(); }

		window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (!window) {
			glfwTerminate();
			abort();
		}

		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to Initialize GLAD" << std::endl;
			abort();
		}
	}

	GLFWwindow* Window::GetWindow() {
		return window;
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Window::mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
		float xpos = static_cast<float>(xposIn);
		float ypos = static_cast<float>(yposIn);

		//std::cout << "I am here";

		//mxpos = xpos;
		//mypos = ypos;
	}

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		btn = button;
		act = action;
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (action == GLFW_PRESS) {
				isclicked = true;
				glfwGetCursorPos(window, &cxpos, &cypos);
				//std::cout << "x: " << cxpos << ", y: " << cypos << std::endl;
			}
		}
	}

	bool IsMouseClicked(void) {
		return isclicked;
	}

	std::array<int, 2> GetClickPos() {
		std::array<int, 2> pos;
		if (isclicked = true) {
			pos[0] = cxpos;
			pos[1] = cypos;
		}
		isclicked = false;
		return pos;
	}

}