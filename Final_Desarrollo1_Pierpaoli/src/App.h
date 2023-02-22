#pragma once
#include "ScreenProperties.h"
#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Game.h"
#include "Credits.h"



class App
{

private:
	SceneManager* sceneManager;
	Menu* menu;
	Rules* rules;
	Game* game;
	Credits* credits;

public:
	App();
	~App();
	void start();
};
