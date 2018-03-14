#include <Ressources/Scene.h>
#include "Context/Input.h"

using namespace Ressources;

Scene::Scene(const GLuint& p_windowWidth, const GLuint& p_windowHeight)
	: m_camera {Camera(p_windowWidth, p_windowHeight)}
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
	for (auto& e : m_gameObjects)
	{
		if (e->HasComponent<Shader>())
			m_shaders.push_back(&e->GetComponent<Shader>());
			//m_camera.AddShader(&e->GetComponent<Shader>());
	}
}


void Scene::Update(const float& p_deltaTime)
{
	if (Context::Input::ShouldUpdateMouse())
		m_camera.ProcessMouseMovement(Context::Input::GetXOffset(), Context::Input::GetYOffset());

	m_camera.ProcessKeyboard(Context::Input::GetMovementDirection(), p_deltaTime);

	for (auto& shader : m_shaders)
		m_camera.Update(shader);

	for (auto& g : m_gameObjects)	g->Update();
}

void Scene::LateUpdate()
{
	for (auto& g : m_gameObjects)
	{
		g->GetComponent<Transform>().Update();
		g->LateUpdate();
	}
}

void Scene::Draw()
{
	for (auto& g : m_gameObjects)	g->Draw();
	LateUpdate();
}

void Scene::Clean()
{
	m_gameObjects.erase(std::remove_if(std::begin(m_gameObjects), std::end(m_gameObjects),
		[](const std::unique_ptr<GameObject> &mEntity)
	{
		return !mEntity->IsActive();
	}),
		std::end(m_gameObjects));
}

GameObject& Scene::AddEntity()
{
	GameObject* e = new GameObject();
	std::unique_ptr<GameObject> ePtr{ e };

	e->AddComponent<Transform>();
	m_gameObjects.emplace_back(std::move(ePtr));
	return *e;
}

GameObject& Scene::Cube()
{
	GameObject* e = new GameObject();
	std::unique_ptr<GameObject> ePtr{ e };
	
	ePtr->AddComponent<Shader>("Res/Shaders/lighting.vert", "Res/Shaders/lighting.frag");
	//ePtr->AddComponent<Shader>("Res/Shaders/default.vert", "Res/Shaders/default.frag");
	ePtr->AddComponent<Model>("Res/Models/Primitives/Cube.obj");
	ePtr->AddComponent<Transform>();
	m_gameObjects.emplace_back(std::move(ePtr));
	return *e;
}

GameObject& Scene::Plane()
{
	GameObject* e = new GameObject();
	std::unique_ptr<GameObject> ePtr{ e };

	ePtr->AddComponent<Shader>("Res/Shaders/lighting.vert", "Res/Shaders/lighting.frag");
	//ePtr->AddComponent<Shader>("Res/Shaders/default.vert", "Res/Shaders/default.frag");
	ePtr->AddComponent<Model>("Res/Models/Primitives/Cube.obj");
	ePtr->AddComponent<Transform>();

	auto& transform = ePtr->GetComponent<Transform>();
	transform.SetScale(Vec3f(10, 0.2f, 10));

	m_gameObjects.emplace_back(std::move(ePtr));
	return *e;
}

int Scene::Count()
{
	return m_gameObjects.size();
}
