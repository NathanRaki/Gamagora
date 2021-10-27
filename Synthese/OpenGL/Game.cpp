#include "game.h"

Game::Game(unsigned int width, unsigned int height, std::string tPath, std::string mPath, std::string sPath)
{
	screenWidth = width;
	screenHeight = height;

	srcPath = std::filesystem::current_path().string();
	vShadersPath = srcPath + "\\shaders\\vertex\\";
	fShadersPath = srcPath + "\\shaders\\fragment\\";
	texturesPath = srcPath + tPath;
	modelsPath = srcPath + mPath;
	soundsPath = srcPath + sPath;

	lastX = width / 2.0f;
	lastY = height / 2.0f;
	firstMouse = true;
}

GLFWwindow* Game::Initialize()
{
	// GLFW: Initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// GLFW: Window creation
	// ---------------------
	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// Tell GLFW to capture mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// GLAD: Load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD." << std::endl;
		glfwTerminate();
	}

	// Configure global OpenGL state
	glEnable(GL_DEPTH_TEST);

	// Build and compile our shader programs
	// -------------------------------------
	textureShader = new Shader((vShadersPath + "textureShader.vs").c_str(), (fShadersPath + "textureShader.fs").c_str());
	materialShader = new Shader((vShadersPath + "materialShader.vs").c_str(), (fShadersPath + "materialShader.fs").c_str());
	lightSourceShader = new Shader((vShadersPath + "lightSourceShader.vs").c_str(), (fShadersPath + "lightSourceShader.fs").c_str());
	skyboxShader = new Shader((vShadersPath + "skyboxShader.vs").c_str(), (fShadersPath + "skyboxShader.fs").c_str());

	glfwSetWindowUserPointer(window, this);

	inputEngine.Init(&gameobjects);

	return window;
}

// GLFW: Whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
	// Make sure the viewport matches the new dimensions
	glViewport(0, 0, width, height);
	game->setWidth(width);
	game->setHeight(height);
}

// GLFW: Processing simple press inputs
// ------------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, true); }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
	if (game->getFirstMouse())
	{
		game->setLastX(xpos);
		game->setLastY(ypos);
		game->setFirstMouse(false);
	}
	double xoffset = xpos - game->getLastX();
	double yoffset = game->getLastY() - ypos;
	game->setLastX(xpos);
	game->setLastY(ypos);
}

// GLFW: Whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
}