#include "Macro.h"
#include "../Engine/Source/Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "../Engine/Source/GameWorld/World.h"
#include "GLFW/glfw3.h"

void glfwErrorCallback(int errorCode, const char* description)
{
	BlazeFramework::OpenGL::LogToFileAndConsole("GLFW ERROR: message: %s, error code: %i\n", description, errorCode);
};

World gameWorld;

int main()
{
	gameWorld.GameLoop();

	return 0;
}