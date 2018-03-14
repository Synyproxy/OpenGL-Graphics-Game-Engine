#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Ressources/Shader.h>
#include <Core/Math/vec3f.h>
#include <Physics/Transform.h>
#include <Core/Math/vec2f.h>

using namespace Ressources;
using namespace Core::Math;
using namespace Physics;

namespace LowRenderer
{
	enum CameraMovement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		IDLE
	};

	//Default Values for Camera
	const GLfloat YAW = -90.f;
	const GLfloat PITCH = 0.0f;
	const GLfloat SPEED = 10.f;
	const GLfloat SENSITIVITY = 0.2f;
	const GLfloat ZOOM = 45.0f;

	class Camera
	{
	private:

		Vec3f m_position;
		glm::mat4 m_projection;
		glm::mat4 m_view;
		glm::mat4 m_model;

		GLint m_width;
		GLint m_height;
		GLfloat FOV = 45.0f;
		GLfloat zNear = 0.1f;
		GLfloat zFar = 1000.0f;

		Vec3f m_worldUp;
		Vec3f m_front;
		Vec3f m_right;
		GLfloat m_yaw;
		GLfloat m_pitch;
		GLfloat m_movementSpeed;
		GLfloat m_sensitivity;
		GLfloat m_zoom;


	public:
		Camera(GLint p_width, GLint p_height, Vec3f p_position = Vec3f(0, 0, 0), Vec3f p_up = Vec3f(0.f, 1.0f, 0.f), GLfloat p_yaw = YAW, GLfloat p_pitch = PITCH);
		~Camera();

		void AddShader(Shader* p_shader);
		void Update(Shader* p_shader);

		glm::mat4 GetViewMatrix();
		void UpdateCameraVectors();
		void ProcessKeyboard(const Vec2f& p_movementDirection, float p_deltaTime);
		void ProcessMouseMovement(GLfloat p_xOffset, GLfloat p_yOffset, const GLboolean& p_constrainPitch = true);
		void ProcessMouseScroll(GLfloat p_yOffset);

		GLfloat GetZoom() const;
	};
}