#include "GameObject.h"

GameObject::GameObject() : position(glm::vec3(0.0f)), scale(glm::vec3(1.0f)), rotation(glm::vec3(0.0f)) {}

GameObject::GameObject(glm::vec3 wPos, glm::vec3 s) : position(wPos), scale(s) {}