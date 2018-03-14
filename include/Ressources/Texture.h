#pragma once

#include <GL/glew.h>
#include <string>
#include <assimp/types.h>

namespace Ressources
{
	struct Texture
	{
		GLuint m_id;
		std::string m_type;
		aiString m_path;
	};
}
