#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Rules
{
private:
	SceneManager* sceneManager;

	Rectangle exitBox;
public:
	Rules(SceneManager* sceneManager);
	~Rules();
	void DrawAndUpdate();
};
