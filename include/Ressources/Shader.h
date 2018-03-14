#pragma once

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Ressources/Component.h>

namespace Ressources
{
	class Component;
	class Shader : public Component
	{
	private:
		GLuint m_program;
	public:

		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
		~Shader() = default;

		void Update() override;
		GLuint GetProgram() const;
	};
}
