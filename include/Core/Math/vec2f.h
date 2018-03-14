#pragma once

#include <glm/glm.hpp>

namespace Core
{
	namespace Math
	{
		class Vec2f
		{
		private:
			float m_x;
			float m_y;

		public:
			Vec2f(float p_x = 0, float p_y = 0);
			~Vec2f();
			Vec2f(const Vec2f& other);

			glm::vec2 to_glm() const;

			//Getters
			float X() const;
			float Y() const;
			void X(float p_x);
			void Y(float p_y);

			//Operators
			bool operator==(const Vec2f& other) const;
			Vec2f operator+(const Vec2f& other) const;

			float Magnitude();
			Vec2f Normalize();
		};

	}
}