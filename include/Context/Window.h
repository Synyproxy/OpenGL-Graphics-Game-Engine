#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Ressources/Scene.h>

using namespace Ressources;

namespace Graphics
{
	class Window
	{
	private:
		GLint WIDTH;
		GLint HEIGHT;

		GLFWwindow * m_window;
		Scene* m_scene;
		Time m_time;


	public:
		Window(const GLint& p_width,const GLint& p_height);
		~Window();

		bool Setup();
		void Run();

		void BindInput();
		void InputHandle();
	};
}