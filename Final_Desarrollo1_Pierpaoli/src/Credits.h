#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Credits
{
private:
	SceneManager* sceneManager;

	Texture2D texture;

	Rectangle exitBox;
public:
	Credits(SceneManager* sceneManager);
	~Credits();
	void UpdateAndDraw();

};
