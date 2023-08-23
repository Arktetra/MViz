#include <Platform/MViz.h>

#include <iostream>
#include <array>
#include "UI/Widgets.h"
#include "Utils/Utils.h"

int main() {
	MViz::Window window(800, 600, "APP");

	MViz::Shader program1("res/shaders/", "over.shader", "ofrag.shader");
	program1.Orthogonalize(800, 600);

	std::array<MViz::Vertex, 6> ver = MViz::QuadVertices(55, 55, 100, 10);
	MViz::VA vao(ver);
	
	program1.Use();

	while (!glfwWindowShouldClose(window.GetWindow())) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		vao.Bind();
		MViz::RenderQuad(vao, program1);

		glfwSwapBuffers(window.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}