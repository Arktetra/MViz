#pragma once

#include <iostream>

#include "../Renderer/Shader.h"
#include "../Renderer/Font.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/VertexArray.h"

namespace MViz {
	//void label(std::string title, float x, float y);
	class LabelRenderer {
		Shader bgShader;
		Shader txtShader;
		Font font;
		VA bgVAO;
		VA txtVAO;
	public:
		/*LabelRenderer(std::string title, float x, float y) :
			bgShader("/res/shaders/", "over.shader", "ofrag.shader"),
			txtShader("/res/shaders/", "text.vs", "text.fs"),
			font("res/fonts/BRADHITC.TTF"),*/

	};
}