#include "Widgets.h"

namespace MViz {
	void LabelRenderer::Render() {
		RenderQuad(bgVAO, bgShader, vertices);
		RenderText(font, txtShader, txtVAO, label, lxpos, lypos, scale, glm::vec3(0.0f, 0.0f, 0.0f));
	}

	void ButtonRenderer::Render() {
		RenderQuad(bgVAO, bgShader, indices);
		RenderText(font, txtShader, txtVAO, label, lxpos, lypos, scale, glm::vec3(0.0f, 0.0f, 0.0f));
		ButtonFn();
	}

	void ButtonRenderer::ButtonFn() {
		if (IsMouseClicked()) {
			std::array<int, 2> pos = GetClickPos();
			int xpos = pos[0];
			int ypos = -(pos[1] - 600);

			if (vertices[0].position[0] < xpos && vertices[1].position[0] > xpos
				&& vertices[0].position[1] < ypos && vertices[2].position[1] > ypos) {
				(*fnptr)();
			}
		}
	}

	void Default() { std::cout << "This is a button"; }
}