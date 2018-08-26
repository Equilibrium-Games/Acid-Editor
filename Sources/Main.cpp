#include <iostream>
#include <Files/Files.hpp>
#include <Helpers/FileSystem.hpp>
#include <Inputs/Mouse.hpp>
#include <Renderer/Renderer.hpp>
#include <Scenes/Scenes.hpp>
#include "MainUpdater.hpp"
#include "MainRenderer.hpp"
#include "Scenes/FpsPlayer.hpp"
#include "Scenes/Scene1.hpp"

using namespace test;
using namespace acid;

//#if (ACID_BUILD_RELEASE && ACID_BUILD_WINDOWS)
//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
//#else
int main(int argc, char **argv)
//#endif
{
	// Registers file search paths.
	Files::AddSearchPath("Resources/Editor");
	Files::AddSearchPath("Resources/Engine");

	// Creates the engine and updater objects.
	auto engine = new Engine();
	engine->SetUpdater(new MainUpdater());

	// Registers modules.
//	Engine::Get()->RegisterModule<World>(UPDATE_NORMAL);

	// Registers components.
	Scenes::Get()->RegisterComponent<FpsPlayer>("FpsPlayer");

	// Initializes modules.
	Display::Get()->SetTitle("Microverse");
	Display::Get()->SetIcon("Logos/Microverse.png");
	Mouse::Get()->SetCustomMouse("Guis/Cursor.png");
	Renderer::Get()->SetManager(new MainRenderer());
	Scenes::Get()->SetScene(new Scene1());

	// Runs the game loop.
	auto exitCode = engine->Run();
	delete engine;

	// Pauses the console.
	std::cin.get();
	return exitCode;
}
