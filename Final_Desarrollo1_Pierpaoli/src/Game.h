#pragma once
#include <vector>

#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include "Level.h"
#include "PowerUp.h"

#include "SceneManager.h"

class Game
{
private:
	SceneManager* sceneManager;

	Player* player;
	Ball* ball;

	static const int rows = 15;
	static const int columns = 6;

	Brick* bricks[rows][columns];

	Level* level;

	std::vector<PowerUp*> powerUps;
	int rndPowerUpActivation;

	bool win;
	bool pause;
	
	// Line separating game and HUD
	int startLinePosX = 1;	
	int endLinePosX = GetScreenWidth() - 1;
	int linePosY = GetScreenHeight() - 50;

	Sound ballSound;
	Sound victorySound;
	Sound defeatSound;

	Texture2D ballTexture;
	Texture2D playerTexture;

	Texture2D redBrickTexture;
	Texture2D orangeBrickTexture;
	Texture2D yellowBrickTexture;
	Texture2D greenBrickTexture;
	Texture2D skyblueBrickTexture;
	Texture2D blueBrickTexture;

	Texture2D addLifeTexture;
	Texture2D reduceLifeTexture;
	Texture2D addSpeedTexture;
	Texture2D reduceSpeedTexture;

public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

};
