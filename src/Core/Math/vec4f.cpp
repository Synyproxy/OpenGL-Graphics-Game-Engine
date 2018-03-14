#include <Core/Math/vec4f.h>

using namespace Core::Math;

Vec4f::Vec4f(float p_x, float p_y, float p_z, float p_w)
		: m_x {p_x}, m_y {p_y}, m_z {p_z}, m_w {p_w}
{

}

Vec4f::~Vec4f()
{

}

glm::vec4 Vec4f::to_glm() const
{
	return glm::vec4(m_x, m_y, m_z, m_w);
}