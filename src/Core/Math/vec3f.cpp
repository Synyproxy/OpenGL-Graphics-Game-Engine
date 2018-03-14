#include <Core/Math/vec3f.h>

using namespace Core::Math;

Vec3f::Vec3f(float p_x, float p_y, float p_z)
	: m_x{ p_x}, m_y{ p_y}, m_z{p_z}
{
}

Vec3f::~Vec3f()
{
}

Vec3f::Vec3f(const Vec3f& other)
{
	m_x = other.X();
	m_y = other.Y();
	m_z = other.Z();
}

glm::vec3 Vec3f::to_glm() const
{
	return glm::vec3(m_x, m_y, m_z);
}

Vec3f Vec3f::operator-(const Vec3f& other) const
{
	return Vec3f(m_x - other.X(), m_y - other.Y(), m_z - other.Z());
}

Vec3f Vec3f::operator+(const Vec3f& other) const
{
	return Vec3f(m_x + other.X(), m_y + other.Y(), m_z + other.Z());
}

Vec3f Vec3f::operator*(const float& p_scalar) const
{
	return Vec3f(m_x * p_scalar, m_y * p_scalar, m_z * p_scalar);
}

bool Vec3f::operator==(const Vec3f& other) const
{
	return (m_x == other.X() && m_y == other.Y() && m_z == other.Z());
}

Vec3f Vec3f::up()
{
	return Vec3f(0, 1, 0);
}

Vec3f Vec3f::Normalize()
{
	float magnitude = Magnitude();

	if (magnitude != 0)
	{
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
	}
	
	return *this;
}

float Vec3f::Magnitude()
{
	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

Vec3f Vec3f::Cross(const Vec3f& other) const
{
	return Vec3f((m_y * other.Z()) - (m_z * other.Y()), (m_z * other.X()) - (m_x * other.Z()), (m_x * other.Y()) - (m_y * other.X()));
}

float Vec3f::X() const
{
	return m_x;
}

float Vec3f::Y() const
{
	return m_y;
}

float Vec3f::Z() const
{
	return m_z;
}

void Vec3f::X(float p_x)
{
	m_x = p_x;
}

void Vec3f::Y(float p_y)
{
	m_y = p_y;
}

void Vec3f::Z(float p_z)
{
	m_z = p_z;
}
