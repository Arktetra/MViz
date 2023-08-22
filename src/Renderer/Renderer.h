#pragma once

#include <glad/glad.h>

#include "Font.h"
#include "Shader.h"
#include "VertexArray.h"

namespace MViz {
	class Renderer {
	public:
		void RenderText(MViz::Font& font, MViz::Shader& shader, MViz::VA & VAO, std::string Text, float x, float y, float scale, glm::vec3 color);
		void RenderQuad(MViz::Shader& shader, MViz::VA& VAO);
	};
}