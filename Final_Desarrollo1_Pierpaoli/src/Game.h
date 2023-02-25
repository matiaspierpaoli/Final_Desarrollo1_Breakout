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

	// Filas y columnas de ladrillos
	static const int rows = 15; 
	static const int columns = 6;

	int rndPowerUpActivation; // Random para activar powerUps en Update()

	bool win; // Condicion de victoria/derrota
	bool pause; // Condicion de pausa

	SceneManager* sceneManager; // Copia desde App

	Player* player;
	Ball* ball;
	Brick* bricks[rows][columns];
	Level* level;

	std::vector<PowerUp*> powerUps;
	
	
	// Line separating game and HUD
	int startLinePosX = 1;	
	int endLinePosX = GetScreenWidth() - 1;
	int linePosY = GetScreenHeight() - 50;

	// Efectos de sonido
	Sound ballSound;
	Sound victorySound;
	Sound defeatSound;

	// Texturas
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

	Texture2D victoryScreenTexture;
	Texture2D defeatScreenTexture;

public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();

	void Reset();

};
