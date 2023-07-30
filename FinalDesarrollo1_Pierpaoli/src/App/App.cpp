#include <iostream>
#include "App.h"

namespace BreakoutGame
{
	App::App()
	{
		// Inicializacion de pantalla mediante raylib
		InitWindow(screenWidth, screenHeight, "Breakout by Matias Pierpaoli");
		InitAudioDevice(); // Sistema de audio

		srand(static_cast<unsigned int>(time(nullptr))); // Semilla para el random

		// El manager original de cambio de pantallas
		sceneManager = new SceneManager();

		// Musica
		music = LoadMusicStream("res/music.mp3");
		SetMusicVolume(music, 0.2f);
		music.looping = true;

		// Inicializacion de objetos tipo pantallas en memoria dinamica
		menu = new Menu(sceneManager);
		game = new Game(sceneManager, music);
		rules = new Rules(sceneManager);
		credits = new Credits(sceneManager);

		shouldExit = false;
	}

	App::~App()
	{
		// Eliminacion de espacio en el heap
		delete sceneManager;
		delete menu;
		delete rules;
		delete credits;

		game->DeInit();
		delete game;

		// Cierre de musica, sonido y ventana
		UnloadMusicStream(music);
		CloseWindow();
		CloseAudioDevice();
	}

	void App::start()
	{
		game->Init(); // Inicializacion de objetos de juegos, booleanos y carga de texturas
		PlayMusicStream(music);

		while (!shouldExit && sceneManager->getScene() != Scene::EXIT) // Loop princiapl de cierre y cambio de ventana
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
				shouldExit = true;
				break;
			default:
				break;
			}
		}
	}
}