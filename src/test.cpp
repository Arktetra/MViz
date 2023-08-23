#include <Platform/MViz.h>

#include <iostream>

#include "UI/Widgets.h"

float vertices[] = {
	0.0f, 0.0f, 0.0f,
	-0.5f, 0.0f, 0.0f,
	0.0f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

unsigned int indices[] = {
	0, 1, 2,
	1, 2, 3
};

float vertices2[] = {
	0.0f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f
};

unsigned int indices2[] = {
	0, 1, 2,
	1, 2, 3
};

int main() {
	MViz::Window window(800, 600, "APP");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	MViz::Shader program1("res/shaders/", "ver.shader", "frag.shader");
	MViz::VA array(vertices, indices, sizeof(vertices), sizeof(indices));
	MViz::VA array2(vertices2, indices2, sizeof(vertices2), sizeof(indices2));
	
	MViz::Shader program2("res/shaders/", "text.vs", "text.fs");
	program2.Orthogonalize(800, 600);
	MViz::VA array3;
	MViz::Font font("res/fonts/BRADHITC.TTF");

	while (!glfwWindowShouldClose(window.GetWindow())) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		MViz::RenderQuad(program1, array);
		MViz::RenderQuad(program1, array2);
		MViz::RenderText(font, program2, array3, "Hello", 25.0f, 25.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
		MViz::RenderText(font, program2, array3, "Hi", 500.0f, 400.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));

		glfwSwapBuffers(window.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;

}