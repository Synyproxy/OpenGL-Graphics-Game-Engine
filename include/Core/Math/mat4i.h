#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core
{
	namespace Math
	{
		class Mat4i
		{
		private:
			int* m_matrice;

		public:
			Mat4i(int p_matrice[16]);
			~Mat4i();

			glm::mat4 to_glm() const;
		};
	}
}