#include <Platform/MViz.h>

#include <iostream>

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

	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	MViz::VA array(vertices, indices, sizeof(vertices), sizeof(indices));
	MViz::VA array2(vertices2, indices2, sizeof(vertices2), sizeof(indices2));
	MViz::Shader program1("res/shaders/", "ver.shader", "frag.shader");
	MViz::Renderer renderer;

	MViz::Shader program2("res/shaders/", "text.vs", "text.fs");
	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	program2.Use();
	glUniformMatrix4fv(glGetUniformLocation(program2.GetProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	MViz::VA array3;
	MViz::Font font("res/fonts/BRADHITC.TTF");


	while (!glfwWindowShouldClose(window.GetWindow())) {
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.RenderQuad(program1, array);
		renderer.RenderQuad(program1, array2);
		renderer.RenderText(font, program2, array3, "Hello", 25.0f, 25.0f, 1.0f, glm::vec3(0.5f, 0.5f, 0.5f));
		renderer.RenderText(font, program2, array3, "Hi", 500.0f, 400.0f, 1.0f, glm::vec3(0.6f, 0.6f, 0.6f));

		glfwSwapBuffers(window.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}