#include "Game.h"

Game::Game(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}

Game::~Game()
{

}

void Game::Init()
{
	player = new Player();
	ball = new Ball();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			brick[i][j] = new Brick();
		}
	}
		
	level = new Level();

	//level->setMapLevel1();
	
}

void Game::Input()
{

}

void Game::Update()
{

}

void Game::Draw()
{

}

void Game::DeInit()
{
	delete player;
	delete ball;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			delete brick[i][j];
		}
	}

	delete level;
}
