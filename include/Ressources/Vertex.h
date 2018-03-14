#pragma once

#include <glm/glm.hpp>

namespace Ressources
{
	struct Vertex
	{
		// Position
		glm::vec3 Position;
		// Normal
		glm::vec3 Normal;
		// TexCoords
		glm::vec2 TexCoords;
	};
}