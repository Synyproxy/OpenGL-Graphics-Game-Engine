#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Ressources/Shader.h>
#include <LowRenderer/Mesh.h>
#include <Ressources/Component.h>

namespace Ressources
{
	using namespace LowRenderer;
	
	class Model : public Component
	{
	private:

		std::vector<Mesh> m_meshes;
		std::string m_directory;
		std::vector<Texture> m_loadedTextures;
		Shader* m_shader;

		void loadModel(std::string p_path);
		void processNode(aiNode* p_node, const aiScene* p_scene);

		Mesh processMesh(aiMesh* p_mesh, const aiScene *scene);

		std::vector<Texture> loadMaterialTextures(aiMaterial* p_material, aiTextureType p_type, std::string p_typeName);
		GLint TextureFromFile(const char* p_path, std::string p_directory);
	public:
		Model(std::string p_path);
		~Model();

		void Awake() override;
		void Update() override;
		void Draw() override;
		void LateUpdate() override;
	};

}
