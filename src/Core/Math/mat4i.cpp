#include <Core/Math/mat4i.h>

using namespace Core::Math;

Mat4i::Mat4i(int p_matrice[16])
	: m_matrice{ p_matrice }
{

}

Mat4i::~Mat4i()
{
}

glm::mat4 Mat4i::to_glm() const
{
	return glm::make_mat4(m_matrice);
}
