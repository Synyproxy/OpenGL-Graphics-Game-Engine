#include <Core/Math/vec2f.h>

using namespace Core::Math;

Vec2f::Vec2f(float p_x, float p_y)
	: m_x{ p_x }, m_y{ p_y }
{
}

Vec2f::~Vec2f()
{
}

Vec2f::Vec2f(const Vec2f& other)
{
	m_x = other.X();
	m_y = other.Y();
}

glm::vec2 Vec2f::to_glm() const
{
	return glm::vec2(m_x, m_y);
}

float Vec2f::X() const
{
	return m_x;
}

float Vec2f::Y() const
{
	return m_y;
}

void Vec2f::X(float p_x)
{
	m_x = p_x;
}

void Vec2f::Y(float p_y)
{
	m_y = p_y;
}

bool Vec2f::operator==(const Vec2f& other) const
{
	return (m_x == other.X() && m_y == other.Y());
}

Vec2f Vec2f::operator+(const Vec2f& other) const
{
	return Vec2f(m_x + other.X(), m_y + other.Y());
}

float Vec2f::Magnitude()
{
	return sqrt((m_x * m_x) + (m_y * m_y));
}

Vec2f Vec2f::Normalize()
{
	float magnitude = Magnitude();

	if(magnitude != 0)
	{
		m_x /= magnitude;
		m_y /= magnitude;
	}

	return *this;
}
