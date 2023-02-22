#pragma once
#include "ScreenProperties.h"
#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Game.h"




class App
{

private:
	SceneManager* sceneManager;
	Menu* menu;
	Rules* rules;
	Game* game;

public:
	App();
	~App();
	void start();
};
