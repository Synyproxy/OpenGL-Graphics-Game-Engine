#pragma once

#include <glm/glm.hpp>

namespace Core
{
	namespace Math
	{
		class Vec2i
		{
		private:
			int m_x;
			int m_y;

		public:
			Vec2i(int p_x = 0, int p_y = 0);
			~Vec2i();

			glm::vec2 to_glm() const;
		};
	}
}