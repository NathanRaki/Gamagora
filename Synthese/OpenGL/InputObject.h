#pragma once

#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <iostream>

class InputObject : public virtual GameObject
{
public:
	// Interpret input
	virtual void inputCallback(GLFWwindow* window);
	virtual void inputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

class InputEngine
{
public:
	std::vector<InputObject*> managed;

	void Init(std::vector<GameObject*>*);
	void Update(GLFWwindow* window);
	void Update(GLFWwindow* window, int key, int scancode, int action, int mods);
};