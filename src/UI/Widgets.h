#pragma once

#include <iostream>

#include "../Renderer/Shader.h"
#include "../Renderer/Font.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/VertexArray.h"
#include "../Core/window.h"

namespace MViz {
	void Default();

	class LabelRenderer {
		std::string label;
		float lxpos, lypos, scale;
		Shader txtShader;
		Shader bgShader;
		Font font;
		VA bgVAO;
		VA txtVAO;
	public:
		LabelRenderer(std::string title, float xpos, float ypos, float scale, float width = 100, float height = 20) :
			label(title), lxpos(xpos - width / 2), lypos(ypos - 3), scale(scale),
			txtShader("res/shaders/", "text.vs", "text.fs"),
			bgShader("res/shaders/", "over.shader", "ofrag.shader"),
			font("res/fonts/REFSAN.TTF"),
			bgVAO(QuadVertices(xpos, ypos, width, height)),
			txtVAO()
		{
			txtShader.Orthogonalize(800, 600);
			bgShader.Orthogonalize(800, 600);
		}
		void Render();
	};

	class ButtonRenderer {
		std::string label;
		float lxpos, lypos, scale;
		std::array<Vertex, 4> vertices;
		Shader txtShader;
		Shader bgShader;
		Font font;
		VA bgVAO;
		VA txtVAO;
		void (*fnptr)();
	public:
		ButtonRenderer(std::string title, float xpos, float ypos, float scale, float width = 50, float height = 50, void (*ptr)() = Default) :
			label(title), lxpos(xpos - width / 2), lypos(ypos - height / 5), scale(scale),
			txtShader("res/shaders/", "text.vs", "text.fs"),
			bgShader("res/shaders/", "over.shader", "ofrag.shader"),
			font("res/fonts/REFSAN.TTF"),
			bgVAO(QuadIndices(xpos, ypos, width, height)),
			txtVAO(),
			fnptr(ptr)
		{
			txtShader.Orthogonalize(800, 600);
			bgShader.Orthogonalize(800, 600);
			vertices = QuadIndices(xpos, ypos, width, height);
		}
		
		void ButtonFn();

		void Render();

	};
}