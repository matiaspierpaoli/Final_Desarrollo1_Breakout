#include <iostream>

#include "App.h"

App::App()
{
	InitWindow(screenWidth, screenHeight, "Breakout by Matias Pierpaoli");

	SetTargetFPS(60);

	sceneManager = new SceneManager();
	menu = new Menu(sceneManager);
	game = new Game(sceneManager);
	rules = new Rules(sceneManager);

}

App::~App()
{
	delete sceneManager;
	delete menu;
	delete rules;

	game->DeInit();
	delete game;

	CloseWindow();
}

void App::start()
{
	game->Init();

	while (!WindowShouldClose() && sceneManager->getScene() != Scene::EXIT)
	{
		switch (sceneManager->getScene())
		{
		case Scene::MENU:
			menu->UpdateAndDraw();
			break;
		case Scene::GAMEPLAY:
			game->Update();
			game->Draw();
			break;
		case Scene::RULES:
			rules->DrawAndUpdate();
			break;
		case Scene::CREDITS:

			break;
		case Scene::EXIT:
			break;
		default:
			break;
		}
	}
}