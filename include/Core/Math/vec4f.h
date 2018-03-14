#pragma once

#include <glm/glm.hpp>

namespace Core
{
	namespace Math
	{
		class Vec4f
		{
		private:
			float m_x;
			float m_y;
			float m_z;
			float m_w;

		public:
			Vec4f(float p_x = 0, float p_y = 0, float p_z = 0, float p_w = 0);
			~Vec4f();

			glm::vec4 to_glm() const;
		};
	}
}