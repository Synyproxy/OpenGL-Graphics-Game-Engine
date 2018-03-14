#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>

#include <Ressources/Shader.h>
#include <Ressources/Texture.h>
#include <Ressources/Vertex.h>

using namespace Ressources;

namespace LowRenderer
{
	class Mesh
	{
	public:
		
		std::vector<Vertex> m_vertices;
		std::vector<GLuint> m_indices;
		std::vector<Texture> m_textures;

		Mesh(std::vector<Vertex> p_vertices, std::vector<GLuint> p_indices, std::vector<Texture> p_textures);
		~Mesh();
		
		void Draw(Shader& p_shader);

	private:

		GLuint VBO;
		GLuint VAO;
		GLuint EBO;

		void Setup();
	};
}