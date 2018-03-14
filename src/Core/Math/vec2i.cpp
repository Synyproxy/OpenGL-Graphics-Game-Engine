#include <Core/Math/vec2i.h>

using namespace Core::Math;

Vec2i::Vec2i(int p_x, int p_y)
	: m_x{ p_x }, m_y{ p_y }
{
}

Vec2i::~Vec2i()
{
}

glm::vec2 Vec2i::to_glm() const
{
	return glm::vec2(m_x, m_y);
}