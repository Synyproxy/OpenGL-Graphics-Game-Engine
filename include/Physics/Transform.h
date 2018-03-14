#pragma once

#include <Core/Math/vec3f.h>
#include <Ressources/Shader.h>

using namespace Core::Math;
using namespace Ressources;

namespace Physics
{
	
	class Transform : public Component
	{
	private:
		Vec3f m_position;
		Vec3f m_scale;
		Vec3f m_rotationAxis;
		float m_rotation;
		Shader* m_shader;

	public:
		Transform();
		~Transform();

		void Awake() override;
		void Update() override;
		void Draw() override;
		void LateUpdate() override;

		void SetPosition(const Vec3f& p_position);
		void SetScale(const Vec3f& p_scale);
		void SetRotationAxis(const Vec3f& p_rotation);
		void SetRotation(const float& p_rotationSpeed);

		const Vec3f& GetPosition() const;
		const Vec3f& GetScale() const;
		const Vec3f& GetRotationAxis() const;
		const float& GetRotation() const;
	};
}