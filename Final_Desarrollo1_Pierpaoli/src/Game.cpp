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
			bricks[i][j] = new Brick();
			bricks[i][j]->setSize(GetScreenWidth() / rows, GetScreenHeight() / 20);
		}
	}
		
	level = new Level();

	level->setMapLevel1(rows, columns, bricks);
	
}

void Game::Input()
{

}

void Game::Update()
{

}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (bricks[i][j]->getState())
			{
				switch (bricks[i][j]->getColor())
				{
				case 0:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, RED);
					break;
				case 1:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, ORANGE);
					break;
				case 2:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, BROWN);
					break;
				case 3:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, YELLOW);
					break;
				case 4:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, GREEN);
					break;
				case 5:
					DrawRectangle(bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y, BLUE);
					break;
				default:
					break;
				}
			}
		}
	}

	EndDrawing();
}

void Game::DeInit()
{
	delete player;
	delete ball;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			delete bricks[i][j];
		}
	}

	delete level;
}
