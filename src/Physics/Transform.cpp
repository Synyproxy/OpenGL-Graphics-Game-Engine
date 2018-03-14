#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Physics/Transform.h>

using namespace Physics;

Transform::Transform()
	:m_position{Vec3f(0, 0, 0)}, m_scale{Vec3f(1, 1, 1)}, m_rotationAxis{Vec3f::up()},
	m_rotation(0)
{

}

Transform::~Transform()
{
}

void Transform::Awake()
{
	if(m_parent->HasComponent<Shader>())
		m_shader = &m_parent->GetComponent<Shader>();	
}

void Transform::Update()
{
	if(m_shader == nullptr)
		m_shader = &m_parent->GetComponent<Shader>();
	
	if(m_shader != nullptr)
	{
		glm::mat4 transform;
		transform = glm::translate(transform, m_position.to_glm());
		transform = glm::scale(transform, m_scale.to_glm());
		transform = glm::rotate(transform, m_rotation, m_rotationAxis.to_glm());
		GLint transformLocation = glGetUniformLocation((*m_shader).GetProgram(), "transform");

		glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transform));
	}
}

void Transform::Draw()
{
	Update();
}

void Transform::LateUpdate()
{
}

void Transform::SetPosition(const Vec3f& p_position)
{
	m_position = p_position;
}

void Transform::SetScale(const Vec3f& p_scale)
{
	m_scale = p_scale;
}

void Transform::SetRotationAxis(const Vec3f& p_rotation)
{
	m_rotationAxis = p_rotation;
}

void Transform::SetRotation(const float& p_rotationSpeed)
{
	m_rotation = p_rotationSpeed;
}

const Vec3f& Transform::GetPosition() const
{
	return m_position;
}

const Vec3f& Transform::GetScale() const
{
	return m_scale;
}

const Vec3f& Transform::GetRotationAxis() const
{
	return m_rotationAxis;
}

const float& Transform::GetRotation() const
{
	return m_rotation;
}
