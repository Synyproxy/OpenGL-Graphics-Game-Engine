#include <Core/Utils/Time.h>

using namespace Core::Utils;

Time::Time()
	: m_lastFrame {(float)glfwGetTime()}, m_deltaTime {0}
{
}

Time::~Time()
{
}

void Time::Update()
{
	m_deltaTime = glfwGetTime() - m_lastFrame;
	m_lastFrame = glfwGetTime();
}

float Time::GetDeltaTime()
{
	return m_deltaTime;
}
