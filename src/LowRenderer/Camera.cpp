#include <LowRenderer/Camera.h>
#include <Core/Debug/Log.h>

using namespace LowRenderer;
using namespace Core::Debug;


Camera::Camera(GLint p_width, GLint p_height, Vec3f p_position, Vec3f p_up, GLfloat p_yaw, GLfloat p_pitch)
	: m_width{ p_width }, m_height{ p_height }, m_position{p_position}, m_worldUp{ p_up }, m_front{ Vec3f(0.f, 0.f, 1.f) },
	m_right{ Vec3f(1.f, 0.f, 0.f) }, m_yaw{ p_yaw }, m_pitch{p_pitch}, m_movementSpeed{ SPEED }, m_sensitivity{ SENSITIVITY }, m_zoom{ ZOOM }
{
	Core::Debug::Log::Logger("Camera Created", LogLevel::SUCCESSS);
	UpdateCameraVectors();
}

Camera::~Camera()
{
}

void Camera::Update(Shader* p_shader)
{
	
	//Projection
	glm::mat4 projection;
	projection = glm::perspective(FOV, (GLfloat)m_width / (GLfloat)m_height, zNear, zFar);
	//projection = glm::ortho(0.0f, (GLfloat)m_width, 0.0f, (GLfloat)m_height, zNear, zFar);
	GLint projectionlLoc = glGetUniformLocation(p_shader->GetProgram(), "projection");
	glUniformMatrix4fv(projectionlLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//View
	glm::mat4 view;
	view = GetViewMatrix();
	GLint viewlLoc = glGetUniformLocation(p_shader->GetProgram(), "view");
	glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(view));

	GLuint viewPos = glGetUniformLocation(p_shader->GetProgram(), "viewPos");
	glUniform3fv(viewPos, 1, glm::value_ptr(m_position.to_glm()));
	
	UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(m_position.to_glm(), m_position.to_glm() + m_front.to_glm(), m_worldUp.to_glm());
}

void Camera::UpdateCameraVectors()
{
	//Calculate front
	Vec3f front;
	front.X(std::cos(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch)));
	front.Y(std::sin(glm::radians(m_pitch)));
	front.Z(std::sin(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch)));
	m_front = front.Normalize();

	//Calculate Right
	m_right = m_front.Cross(m_worldUp).Normalize();
	//m_worldUp = m_right.Cross(m_front).Normalize();	//Relative Up ex: Flight Simulation
}

void Camera::ProcessKeyboard(const Vec2f& p_movementDirection, float p_deltaTime)
{
	GLfloat velocity = m_movementSpeed * p_deltaTime;
	Vec3f newPosition = m_position;

	if (p_movementDirection.Y() < 0)
		newPosition = newPosition + (m_front * velocity);

	if (p_movementDirection.Y() > 0)
		newPosition = newPosition - (m_front * velocity);

	if (p_movementDirection.X() > 0)
		newPosition = newPosition + (m_right * velocity);

	if (p_movementDirection.X() < 0)
		newPosition = newPosition - (m_right * velocity);

	m_position = newPosition;

}

void Camera::ProcessMouseMovement(GLfloat p_xOffset, GLfloat p_yOffset, const GLboolean& p_constrainPitch)
{
	p_xOffset *= m_sensitivity;
	p_yOffset *= m_sensitivity;

	m_yaw += p_xOffset;
	m_pitch += p_yOffset;

	if(p_constrainPitch)
	{
		if (m_pitch > 89.0f)
			m_pitch = 89.0f;

		if (m_pitch < -89.0f)
			m_pitch = -89.0f;
	}

	UpdateCameraVectors(); 
}

void Camera::ProcessMouseScroll(GLfloat p_yOffset)
{
	if(m_zoom >= 1.0f && m_zoom <= 45.0f)
		m_zoom -= p_yOffset;
	
	if (m_zoom <= 1.0f)
		m_zoom = 1.0f;

	if (m_zoom >= 45.0f)
		m_zoom = 45.0f;
}

GLfloat Camera::GetZoom() const
{
	return m_zoom;
}