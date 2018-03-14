#pragma once

#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace Core
{
	namespace Utils
	{
		class Time
		{
		private:
			float m_lastFrame;
			float m_deltaTime;

		public:
			Time();
			~Time();

			void Update();

			float GetDeltaTime();
		};
	}
}