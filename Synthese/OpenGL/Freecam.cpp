#include "Freecam.h"
#include "Game.h"

Freecam::Freecam(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
	Camera(position, up, yaw, pitch), MovementSpeed(SPEED), MouseSensitivity(SENSIVITY)
{
	updateCameraVectors();
}

void Freecam::inputCallback(GLFWwindow* window)
{
	Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
	if (game->cameraMode == FREECAM)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { Move(Front * 0.1f); std::cout << Front.x << " " << Front.y << " " << Front.z << std::endl; }
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { Move(Right * -0.1f); }
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { Move(Front * -0.1f); }
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { Move(Right * 0.1f); }
		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) { Move(Up * 0.1f); }
		if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) { Move(Up * -0.1f); }
	}
}

void Freecam::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;
	Yaw += xoffset;
	Pitch += yoffset;

	if (constrainPitch)
	{
		if (Pitch > 89.0f) { Pitch = 89.0f; }
		else if (Pitch < -89.0f) { Pitch = -89.0f; }
	}
	updateCameraVectors();
}

void Freecam::ProcessMouseScroll(float yoffset)
{
	if (Zoom >= 1.0f && Zoom <= 45.0f) { Zoom -= yoffset; }
	else if (Zoom <= 1.0f) { Zoom = 1.0f; }
	else if (Zoom >= 45.0f) { Zoom = 45.0f; }
}

void Freecam::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}