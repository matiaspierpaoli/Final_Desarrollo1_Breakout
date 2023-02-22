#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Credits
{
private:
	SceneManager* sceneManager;

	Rectangle exitBox;
public:
	Credits(SceneManager* sceneManager);
	~Credits();
	void UpdateAndDraw();

};
