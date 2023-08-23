#include "Widgets.h"

namespace MViz {
	/*void label(std::string title, float x, float y) {
		MViz::Shader program1("res/shaders/", "over.shader", "ofrag.shader");
		program1.Orthogonalize(800, 600);

		float vertices[] = {
			x - 100, y - 10, 0,
			x + 100, y - 10, 0,
			x - 100, y + 20, 0,
			x + 100, y + 20, 0
		};

		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3
		};

		MViz::VA VAO(vertices, indices, sizeof(vertices), sizeof(indices));

		MViz::Shader program2("res/shaders/", "text.vs", "text.fs");
		program2.Orthogonalize(800, 600);
		MViz::Font font("res/fonts/BRADHITC.TTF");
		MViz::VA VAO2;
		MViz::Renderer renderer;
		renderer.RenderQuad(program1, VAO);
		renderer.RenderText(font, program2, VAO2, title, x, y, 0.5f, glm::vec3(0.0f, 0.0f, 0.0f));
	}*/

	/*LabelRenderer::LabelRenderer(std::string title, float x, float y) {
		Shader bgShader("/res/shaders/", "over.shader", "ofrag.shader");
	}*/
}