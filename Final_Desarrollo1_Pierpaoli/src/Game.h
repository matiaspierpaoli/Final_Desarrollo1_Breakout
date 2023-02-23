#pragma once

#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include "Level.h"


#include "SceneManager.h"

class Game
{
private:
	SceneManager* sceneManager;

	Player* player;
	Ball* ball;

	static const int rows = 20;
	static const int columns = 6;

	Brick* bricks[rows][columns];

	Level* level;

	bool win = false;
	int points = 0;
	
	// Line separating game and HUD
	int startLinePosX = 1;	
	int endLinePosX = GetScreenWidth() - 1;
	int linePosY = GetScreenHeight() - 50;
	

public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

};
