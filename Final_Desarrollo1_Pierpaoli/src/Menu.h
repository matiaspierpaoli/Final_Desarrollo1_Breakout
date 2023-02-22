#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Menu
{
private:
	SceneManager* sceneManager;

public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void Update();
	void Draw();
	
};
