#include <Context/Input.h>

using namespace Context;

GLfloat Input::m_windowWidth = 0;
GLfloat Input::m_windowHeight = 0;
bool Input::m_shouldClose = false;

bool Input::m_updateMouse = false;
bool Input::m_firstMouse = true;
GLfloat Input::m_lastX = 0;	 
GLfloat Input::m_lastY = 0;
GLfloat Input::m_xOffset = 0;
GLfloat Input::m_yOffset = 0;

Vec2f Input::m_movementDirection = Vec2f(0, 0);
Vec2f Input::m_vertical = Vec2f(0, 0);
Vec2f Input::m_horizontal = Vec2f(0, 0);


Input::Input()
{
}

Input::~Input()
{
}

void Input::KeyCallBack(GLFWwindow* p_window, int p_key, int p_scanCode, int p_action, int p_mods)
{
	if(p_key == GLFW_KEY_ESCAPE && p_action == GLFW_PRESS)
		m_shouldClose = true;

	if(p_action == GLFW_PRESS)
	{
		if (p_key == GLFW_KEY_W)
			m_vertical.Y(-1);

		if (p_key == GLFW_KEY_S)
			m_vertical.Y(1);

		if (p_key == GLFW_KEY_A)
			m_horizontal.X(-1);

		if (p_key == GLFW_KEY_D)
			m_horizontal.X(1);
	}

	if (p_action == GLFW_RELEASE)
	{
		if (p_key == GLFW_KEY_W)
			m_vertical.Y(0);

		if (p_key == GLFW_KEY_S)
			m_vertical.Y(0);

		if (p_key == GLFW_KEY_A)
			m_horizontal.X(0);

		if (p_key == GLFW_KEY_D)
			m_horizontal.X(0);
	}

	m_movementDirection = m_vertical + m_horizontal;
}

void Input::ScrollCallBack(GLFWwindow* p_window, double p_xOffset, double p_yOffset)
{
	//Camera Zoom
}

void Input::MouseCallBack(GLFWwindow* p_window, double p_xPos, double p_yPos)
{
	m_updateMouse = true;

	if(m_firstMouse)
	{
		m_lastX = p_xPos;
		m_lastY = p_yPos;
		m_firstMouse = false;
	}

	m_xOffset = p_xPos - m_lastX;
	m_yOffset = m_lastY - p_yPos; //Y coordinates are inversed

	m_lastX = p_xPos;
	m_lastY = p_yPos;
}

bool Input::ShouldClode()
{
	return m_shouldClose;
}

bool Input::ShouldUpdateMouse()
{
	return m_updateMouse;
}

GLfloat Input::GetXOffset()
{
	return m_xOffset;
}

GLfloat Input::GetYOffset()
{
	return m_yOffset;
}

Vec2f Input::GetMovementDirection()
{
	return m_movementDirection.Normalize();
}

void Input::Reset()
{
	m_updateMouse = false;
}

void Input::SetWindowSize(const GLfloat& p_windowWidth, const GLfloat& p_windowHeight)
{
	m_windowWidth = p_windowWidth;
	m_windowHeight = p_windowHeight;

	m_lastX = m_windowWidth / 2;
	m_lastY = m_windowHeight / 2;
}
