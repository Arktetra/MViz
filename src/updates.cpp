#include <Platform/MViz.h>

#include <iostream>
#include <array>
#include "UI/Widgets.h"
#include "Utils/Utils.h"

void someFn();

int main() {
	MViz::Window window(800, 600, "APP");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	MViz::Shader program1("res/shaders/", "over.shader", "ofrag.shader");
	program1.Orthogonalize(800, 600);

	std::array<MViz::Vertex, 6> ver = MViz::QuadVertices(55, 55, 100, 10);
	MViz::VA vao(ver);
	program1.Use();

	MViz::Shader program2("res/shaders/", "text.vs", "text.fs");
	program2.Orthogonalize(800, 600);
	MViz::VA array3;
	MViz::Font font("res/fonts/BRADHITC.TTF");

	MViz::LabelRenderer label("label 1", 55, 590, 0.3f);
	MViz::LabelRenderer label2("label 2", 55, 570, 0.3f);

	MViz::ButtonRenderer button("B1", 500, 500, 0.5f, 30, 30, someFn);

	while (!glfwWindowShouldClose(window.GetWindow())) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//vao.Bind();
		//MViz::RenderQuad(vao, program1);
		//MViz::RenderText(font, program2, array3, "Hi", 500.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
		label.Render();
		label2.Render();
		button.Render();
		//window.GetMouseClickPos();

		glfwSwapBuffers(window.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void someFn() {
	std::cout << "This is some function.";
}