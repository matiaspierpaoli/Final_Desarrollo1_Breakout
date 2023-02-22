#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Menu
{
private:

public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void Update();
	void Draw();
	
};
