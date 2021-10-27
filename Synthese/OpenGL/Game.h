#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <filesystem>

#include "Shader.h"
#include "Freecam.h"

enum CameraMode
{
	FREECAM
};

class Game
{
public:
	Game(unsigned int width, unsigned int height, std::string tPath, std::string mPath, std::string sPath);
	GLFWwindow* Initialize();

	std::vector<GameObject*> gameobjects;

	// Camera
	Camera* currentCamera;
	Freecam* freecam;
	CameraMode cameraMode;

	// Shaders
	Shader* textureShader;
	Shader* materialShader;
	Shader* lightSourceShader;
	Shader* skyboxShader;

	// Engines
	InputEngine inputEngine;

	// Path Variables
	std::string srcPath;
	std::string vShadersPath;
	std::string fShadersPath;
	std::string texturesPath;
	std::string modelsPath;
	std::string soundsPath;

	void setWidth(int w) { screenWidth = w; }
	void setHeight(int h) { screenHeight = h;  }
	void setLastX(double x) { lastX = x; }
	void setLastY(double y) { lastY = y; }
	void setFirstMouse(bool f) { firstMouse = f; }

	double getLastX() { return lastX; }
	double getLastY() { return lastY; }
	bool getFirstMouse() { return firstMouse; }

	unsigned int screenWidth;
	unsigned int screenHeight;
	double lastX;
	double lastY;
	bool firstMouse;

};

// GLFW callback functions
// -----------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

#endif