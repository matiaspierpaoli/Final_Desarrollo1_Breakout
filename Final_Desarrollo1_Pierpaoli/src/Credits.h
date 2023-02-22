#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Credits
{
private:
	SceneManager* sceneManager;

public:
	Credits(SceneManager* sceneManager);
	~Credits();
	void UpdateAndDraw();

};
