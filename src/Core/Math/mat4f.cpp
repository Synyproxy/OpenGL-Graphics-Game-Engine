#include <Core/Math/mat4f.h>

using namespace Core::Math;

Mat4f::Mat4f(float p_matrice[16])
		: m_matrice{p_matrice}
{
	
}

Mat4f::~Mat4f()
{
}

glm::mat4 Mat4f::to_glm() const
{
	return glm::make_mat4(m_matrice);
}
