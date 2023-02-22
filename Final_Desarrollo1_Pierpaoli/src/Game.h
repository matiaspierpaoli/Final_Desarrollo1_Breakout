#pragma once

#include "SceneManager.h"
class Game
{
private:
	SceneManager* sceneManager;

public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

};
