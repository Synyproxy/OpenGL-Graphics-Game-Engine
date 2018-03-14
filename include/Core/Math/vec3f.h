#pragma once

#include <glm/glm.hpp>

namespace Core
{
	namespace Math
	{
		class Vec3f
		{
		private:
			float m_x;
			float m_y;
			float m_z;

		public:
			Vec3f(float p_x = 0, float p_y = 0, float p_z = 0);
			~Vec3f();
			Vec3f(const Vec3f& other);

			glm::vec3 to_glm() const;

			//Math
			Vec3f Normalize();
			float Magnitude();
			Vec3f Cross(const Vec3f& other) const;

			//Getters
			float X() const;
			float Y() const;
			float Z() const;
			void X(float p_x);
			void Y(float p_y);
			void Z(float p_z);

			//Operators
			Vec3f operator-(const Vec3f& other) const;
			Vec3f operator+(const Vec3f& other) const;
			Vec3f operator*(const float& p_scalar) const;
			bool operator==(const Vec3f& other) const;

			//Utils
			static Vec3f up();
		};
	}
}