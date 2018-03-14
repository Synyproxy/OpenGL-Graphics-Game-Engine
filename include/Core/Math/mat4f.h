#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core
{
	namespace Math
	{
		class Mat4f
		{
		private:
			float* m_matrice;

		public:
			Mat4f(float p_matrice[16]);
			~Mat4f();

			glm::mat4 to_glm() const;
		};
	}
}