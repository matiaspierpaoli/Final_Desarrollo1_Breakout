#pragma once
#include "ScreenProperties.h"
#include "SceneManager.h"
#include "Menu.h"

#include "Game.h"




class App
{

private:
	SceneManager* sceneManager;
	Menu* menu;

	Game* game;

public:
	App();
	~App();
	void start();
};
