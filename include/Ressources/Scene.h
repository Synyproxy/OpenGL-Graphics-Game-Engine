#pragma once

#include <Ressources/Component.h>
#include <Physics/Transform.h>
#include <Ressources/Model.h>
#include <LowRenderer/Camera.h>
#include <Core/Utils/Time.h>

namespace Ressources
{
	using namespace Physics;
	using namespace Core::Utils;

	class Scene
	{
	private:
		std::vector<std::unique_ptr<GameObject>> m_gameObjects;
		std::vector<Shader*> m_shaders;
		Camera m_camera;
		Time m_time;

	public:
		Scene(const GLuint& p_windowWidth, const GLuint& p_windowHeight);
		~Scene();
		void Init();
		void Update(const float& p_deltaTime);
		void LateUpdate();
		void Draw();
		void Clean();

		GameObject& AddEntity();
		GameObject& Cube();
		GameObject& Plane();

		int Count();	
	};
}
