#pragma once

#include <glm/glm.hpp>

namespace Core
{
	namespace Math
	{
		class Vec3i
		{
		private:
			int m_x;
			int m_y;
			int m_z;

		public:
			Vec3i(int p_x = 0, int p_y = 0, int p_z = 0);
			~Vec3i();

			glm::vec3 to_glm() const;
		};
	}
}