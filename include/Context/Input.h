#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <LowRenderer/Camera.h>
#include <Core/Math/vec2f.h>

using namespace LowRenderer;
using namespace Core::Math;

namespace Context
{
	class Input
	{
	private:

		//Window 
		static GLfloat m_windowWidth;
		static GLfloat m_windowHeight;
		static bool m_shouldClose;

		//Mouse
		static bool m_updateMouse;	//If mouse was updated during frame
		static bool m_firstMouse;
		static GLfloat m_lastX;
		static GLfloat m_lastY;
		static GLfloat m_xOffset;
		static GLfloat m_yOffset;

		//Keyboard
		static Vec2f m_movementDirection;
		static Vec2f m_vertical;
		static Vec2f m_horizontal;

	public:
		Input();
		~Input();

		//OpenGL
		static void KeyCallBack(GLFWwindow* p_window, int p_key, int p_scanCode, int p_action, int p_mods);
		static void ScrollCallBack(GLFWwindow* p_window, double p_xOffset, double p_yOffset);
		static void MouseCallBack(GLFWwindow* p_window, double p_xPos,  double p_yPos);


		static void SetWindowSize(const GLfloat& p_windowWidth, const GLfloat& p_windowHeight);
		static bool ShouldClode();
		static bool ShouldUpdateMouse();
		static GLfloat GetXOffset();
		static GLfloat GetYOffset();
		static Vec2f GetMovementDirection();

		static void Reset();

	
	};
}
