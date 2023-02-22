#pragma once

#include "Player.h"
#include "Ball.h"
#include "Brick.h"

#include "SceneManager.h"
class Game
{
private:
	SceneManager* sceneManager;

	Player* player;
	Ball* ball;

	static const int rows = 30;
	static const int columns = 6;

	Brick* brick[rows][columns];

public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

};
