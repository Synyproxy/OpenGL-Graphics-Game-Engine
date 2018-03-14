#include <Core/Math/vec3i.h>

using namespace Core::Math;

Vec3i::Vec3i(int p_x, int  p_y, int p_z)
	: m_x{ p_x }, m_y{ p_y }, m_z{ p_z }
{
}

Vec3i::~Vec3i()
{
}

glm::vec3 Vec3i::to_glm() const
{
	return glm::vec3(m_x, m_y, m_z);
}