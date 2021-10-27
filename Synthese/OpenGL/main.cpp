#include "Game.h"

int main()
{
	Game game(1280, 720, "textures/", "models/", "sounds/");
	game.freecam = new Freecam(glm::vec3(0.0f));
	game.currentCamera = game.freecam;
	game.cameraMode = FREECAM;

	// Lighting options
	// ----------------
	glm::vec3 lightColor(1.0f);
	glm::vec3 lDiffuse = lightColor * glm::vec3(0.8f);
	glm::vec3 lAmbient = lDiffuse * glm::vec3(0.2f);
	glm::vec3 Specular(1.0f);
	glm::vec3 lightPos(100.0f, 10.0f, 100.0f);
	lightPos.x *= -0.64f;
	lightPos.z *= -0.77f;

	GLFWwindow* window = game.Initialize();

	// Render loop, called every frame
	// -------------------------------
	while (!glfwWindowShouldClose(window))
	{
		game.inputEngine.Update(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection = glm::perspective(glm::radians(game.currentCamera->Zoom), (float)game.screenWidth / (float)game.screenHeight, 0.1f, 100.0f);
		glm::mat4 view = game.currentCamera->GetViewMatrix();

		game.lightSourceShader->use();
		game.lightSourceShader->setMat4("projection", projection);
		game.lightSourceShader->setMat4("view", view);

		// GLFW: Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}