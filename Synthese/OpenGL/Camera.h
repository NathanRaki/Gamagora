#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

#include "InputObject.h"

const float YAW = -90.0f;
const float PITCH = -30.0f;
const float SPEED = 2.5f;
const float SENSIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera : public InputObject
{
public:
	// Camera attributes
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// Eular angles;
	float Yaw;
	float Pitch;
	float Zoom;
	
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = YAW,
		float pitch = PITCH);
	// Returns the view matrix calculated using Eular angles and the LookAt matrix
	glm::mat4 GetViewMatrix();
};