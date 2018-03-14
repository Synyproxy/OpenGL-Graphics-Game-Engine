#pragma once

#include <GLFW/glfw3.h>

namespace Core
{
	namespace Utils
	{
		class Timer
		{
		private:
			float m_startTime;

		public:
			Timer();
			~Timer();

			void Reset();
			float GetElapsed() const;
		};
	}
}