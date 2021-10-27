#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GameObject
{
public:
	std::string name;
	// Transformation variables
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	glm::vec3 worldPosition() { return position; }
	glm::vec3 worldRotation() { return rotation; }
	void Move(glm::vec3 delta) { position += delta; }
	void MoveTo(glm::vec3 pos) { position = pos; }

	GameObject();
	GameObject(glm::vec3, glm::vec3);
	virtual ~GameObject() = default;
};