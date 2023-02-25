#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Rules
{
private:
	SceneManager* sceneManager;

	Texture2D texture;

	Rectangle exitBox;
public:
	Rules(SceneManager* sceneManager);
	~Rules();
	void Draw();
	void Update();
};

