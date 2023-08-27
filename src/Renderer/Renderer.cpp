#include "Renderer.h"

namespace MViz {
	void RenderText(MViz::Font& font, MViz::Shader& shader, MViz::VA & VAO, std::string text, float x, float y, float scale, glm::vec3 color) {
		shader.Use();
		glUniform3f(glGetUniformLocation(shader.GetProgramID(), "textColor"), color.x, color.y, color.z);
		glActiveTexture(GL_TEXTURE0);
		VAO.Bind();

		std::string::const_iterator c;
		for (c = text.begin(); c != text.end(); c++) {
			Character ch = font.Characters[*c];

			float xpos = x + ch.Bearing.x * scale;
			float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

			float w = ch.Size.x * scale;
			float h = ch.Size.y * scale;

			float vertices[6][4] = {
				{ xpos,     ypos + h,   0.0f, 0.0f },
				{ xpos,     ypos,       0.0f, 1.0f },
				{ xpos + w, ypos,       1.0f, 1.0f },

				{ xpos,     ypos + h,   0.0f, 0.0f },
				{ xpos + w, ypos,       1.0f, 1.0f },
				{ xpos + w, ypos + h,   1.0f, 0.0f }
			};
			glBindTexture(GL_TEXTURE_2D, ch.TextureID);
			glBindBuffer(GL_ARRAY_BUFFER, VAO.GetBufferID());
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			glDrawArrays(GL_TRIANGLES, 0, 6);

			x += (ch.Advance >> 6) * scale;
		}
		VAO.Unbind();
		glBindTexture(GL_TEXTURE_2D, 0);

	}

	void RenderQuad(MViz::Shader& shader, MViz::VA& VAO) {
		shader.Use();
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
		VAO.Unbind();
	}

	void RenderQuad(MViz::VA& VAO, MViz::Shader& shader, type t) {
		shader.CheckOrtho();
		shader.Use();
		VAO.Bind();
		if (t == vertices) { glDrawArrays(GL_TRIANGLES, 0, 6); }
		if (t == indices) { glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0); }
		VAO.Unbind();
	}
}