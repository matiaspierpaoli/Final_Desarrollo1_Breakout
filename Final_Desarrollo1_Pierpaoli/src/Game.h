#pragma once


#include "SceneManager.h"
class Game
{
private:


public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

};
