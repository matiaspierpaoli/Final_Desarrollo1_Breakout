#include <iostream>

#include "App.h"

App::App()
{
	InitWindow(screenWidth, screenHeight, "Breakout by Matias Pierpaoli");
	InitAudioDevice();

	srand(time(NULL));

	SetTargetFPS(60);

	sceneManager = new SceneManager();
	menu = new Menu(sceneManager);
	game = new Game(sceneManager);
	rules = new Rules(sceneManager);
	credits = new Credits(sceneManager);

	music = LoadMusicStream("../res/music.mp3");
	SetMusicVolume(music, 0.2f);
	music.looping = true;
}

App::~App()
{
	delete sceneManager;
	delete menu;
	delete rules;
	delete credits;

	game->DeInit();
	delete game;

	UnloadMusicStream(music);
	CloseWindow();
	CloseAudioDevice();
}

void App::start()
{
	game->Init();
	PlayMusicStream(music);

	while (!WindowShouldClose() && sceneManager->getScene() != Scene::EXIT)
	{
		UpdateMusicStream(music);
		switch (sceneManager->getScene())
		{
		case Scene::MENU:
			menu->Update();
			menu->Draw();
			break;
		case Scene::GAMEPLAY:
			game->Input();
			game->Update();
			game->Draw();
			break;
		case Scene::RULES:
			rules->Update();
			rules->Draw();
			break;
		case Scene::CREDITS:
			credits->Update();
			credits->Draw();
			break;
		case Scene::EXIT:
			break;
		default:
			break;
		}
	}
}