#include "InputObject.h"

void InputObject::inputCallback(GLFWwindow* window) {}
void InputObject::inputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {}

void InputEngine::Init(std::vector<GameObject*>* gameobjects)
{
	managed.clear();
	// Go through all GameObjects and check if it is an InputObject
	for (unsigned int i = 0; i < gameobjects->size(); ++i)
	{
		GameObject* gameobject = gameobjects->at(i);
		InputObject* cast = dynamic_cast<InputObject*>(gameobject);
		if (cast) { managed.push_back(cast); }
	}
}

void InputEngine::Update(GLFWwindow* window)
{
	for (auto inputobject : managed)
	{
		inputobject->inputCallback(window);
	}
}

void InputEngine::Update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	for (auto inputobject : managed)
	{
		inputobject->inputCallback(window, key, scancode, action, mods);
	}
}