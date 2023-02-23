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
	Rectangle creditsBox;
	Rectangle exitBox;

	Texture2D texture;
	

public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void UpdateAndDraw();
	
};
