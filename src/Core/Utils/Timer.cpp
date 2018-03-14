#include <Core/Utils/Timer.h>

using namespace Core::Utils;

Timer::Timer()
	: m_startTime {(float)glfwGetTime()}
{

}

Timer::~Timer()
{
}

void Timer::Reset()
{
	m_startTime = glfwGetTime();
}

float Timer::GetElapsed() const
{
	return (glfwGetTime() - m_startTime);
}
