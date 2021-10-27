#ifndef SHADER_H
#define SHADER_h

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
	// The program ID
	unsigned int ID;

	Shader();
	Shader(const char* vertexPath, const char* fragmentPath);
	
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

	void setVec3(const std::string& name, const glm::vec3& vec) const;

	void setMat4(const std::string& name, const glm::mat4& mat) const;
	void setVec4(const std::string& name, const glm::vec4& vec) const;

private:
	// Utility functions for checking shader compilation/linking errors
	// ----------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif