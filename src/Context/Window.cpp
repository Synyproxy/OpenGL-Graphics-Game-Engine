#include <Context/Window.h>
#include <Core/Debug/Log.h>
#include <Ressources/Model.h>
#include <Physics/Transform.h>
#include <Context/Input.h>

using namespace Graphics;
using namespace Core::Debug;
using namespace Ressources;
using namespace Physics;

Window::Window(const GLint& p_width, const GLint& p_height)
	: WIDTH{ p_width }, HEIGHT{ p_height }
{
}

Window::~Window()
{
	if (m_scene != nullptr)
		delete m_scene;
}

bool Window::Setup()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Architecture", nullptr, nullptr);

	int screenWidth, screenHeight;

	if (m_window == nullptr)
	{
		Log::Logger("FAILED::GLFW_CREATE_WINDOW", __FILE__, __LINE__, LogLevel::FATAL_ERR);
		glfwTerminate();

		return false;
	}

	glfwGetFramebufferSize(m_window, &screenWidth, &screenHeight);

	glfwMakeContextCurrent(m_window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		Log::Logger("FAILED::INITIALIZE_GLEW", __FILE__, __LINE__, LogLevel::FATAL_ERR);

		return false;
	}

	Log::Logger("Window Created", LogLevel::SUCCESSS);

	glViewport(0, 0, screenWidth, screenHeight);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);	//Remove Mouse
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	BindInput();

	return true;
}

void Window::Run()
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//WireFrame
	Scene scene(WIDTH, HEIGHT);

	GameObject& newPlayer(scene.AddEntity());
	newPlayer.AddComponent<Shader>("Res/Shaders/lighting.vert", "Res/Shaders/lighting.frag");
	//newPlayer.AddComponent<Shader>("Res/Shaders/default.vert", "Res/Shaders/default.frag");
	newPlayer.AddComponent<Model>("Res/Models/nano/nanosuit.obj");
	auto& playerTransform = newPlayer.GetComponent<Transform>();
	playerTransform.SetPosition(Vec3f(0.0f, 0.0f, -10.f));
	playerTransform.SetScale(Vec3f(0.3f, 0.3f, 0.3f));

	////////////////////////////////////////
	GameObject& cube(scene.Cube());
	auto& transform = cube.GetComponent<Transform>();
	transform.SetPosition(Vec3f(-5.0f, 0.f, -10.f));	

	GameObject& cube2(scene.Cube());
	auto& transform2 = cube2.GetComponent<Transform>();
	transform2.SetPosition(Vec3f(5.0f, 0.f, -10.0f));

	GameObject& plane(scene.Plane());
	auto& transform6 = plane.GetComponent<Transform>();
	transform6.SetPosition(Vec3f(0, -5, 0));
	
	scene.Init();

	while (!glfwWindowShouldClose(m_window))
	{ 
		m_time.Update();

		glfwPollEvents();
		InputHandle();

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene.Update(m_time.GetDeltaTime());
		scene.Draw();

		playerTransform.SetRotation(-1.f * (GLfloat)glfwGetTime());

		Context::Input::Reset();
		glfwSwapBuffers(m_window);
	}
}

void Window::BindInput()
{
	Context::Input::SetWindowSize(WIDTH, HEIGHT);
	glfwSetKeyCallback(m_window, Context::Input::KeyCallBack);
	glfwSetCursorPosCallback(m_window, Context::Input::MouseCallBack);
	glfwSetScrollCallback(m_window, Context::Input::ScrollCallBack);
}

void Window::InputHandle()
{
	if (Context::Input::ShouldClode())
		glfwSetWindowShouldClose(m_window, GL_TRUE);
}
