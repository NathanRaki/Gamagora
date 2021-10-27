#include "camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch)
{
	position = pos;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(worldPosition(), worldPosition() + Front, Up);
}