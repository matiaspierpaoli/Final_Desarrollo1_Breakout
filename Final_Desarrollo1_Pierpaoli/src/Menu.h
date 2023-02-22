#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Menu
{
private:
	SceneManager* sceneManager;

	Rectangle titleBox;
	Rectangle playBox;
	Rectangle rulesBox;
	Rectangle exitBox;
	

public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void UpdateAndDraw();
	
};
