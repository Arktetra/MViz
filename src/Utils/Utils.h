#pragma once

#include <array>

namespace MViz {

	enum type { vertices, indices };

	struct Vertex {
		std::array<float, 3> position;
	};

	static std::array<Vertex, 6> QuadVertices(float xpos, float ypos, float width, float height) {
		width = width / 2;
		height = height / 2;
		std::array<Vertex, 6> vertices = {
			Vertex{{xpos - width, ypos - height, 0}},
			Vertex{{xpos + width, ypos - height, 0}},
			Vertex{{xpos - width, ypos + height, 0}},
			Vertex{{xpos + width, ypos - height, 0}},
			Vertex{{xpos - width, ypos + height, 0}},
			Vertex{{xpos + width, ypos + height, 0}}
		};

		return vertices;
	}

	static std::array<Vertex, 4> QuadIndices(float xpos, float ypos, float width, float height) {
		width = width / 2;
		height = height / 2;
		std::array<Vertex, 4> vertices = {
			Vertex{{xpos - width, ypos - height, 0}},
			Vertex{{xpos + width, ypos - height, 0}},
			Vertex{{xpos - width, ypos + height, 0}},
			Vertex{{xpos + width, ypos + height, 0}},
		};

		return vertices;
	}
}