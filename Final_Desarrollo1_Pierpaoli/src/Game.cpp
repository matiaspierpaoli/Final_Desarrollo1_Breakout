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
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
		player->moveLeft();
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
		player->moveRight();

	// Ball Movement
	if (ball->getActive())	
		ball->move();	
	else	
		ball->setSpeed({ player->getPos().x + player->getSize().x / 2, player->getPos().y - ball->getRadius() });
	

	// Ball - Walls collisions
	if (ball->checkCollisionWithWalls()) // Only true if ball hits wall below player
	{
		ball->reset(player->getPos(), player->getSize());
		player->reduceLives();
	}

	// Ball - Player collisions
	ball->checkCollisionWithPlayer(player->getPos(), player->getSize());

	// Ball - Bricks collisions
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (bricks[i][j]->getActive())
			{
				if (CheckCollisionCircleRec(ball->getPos(), static_cast<float>(ball->getRadius()), {bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y}))
				{
					bricks[i][j]->setState(false);
					ball->changeYDirection();
				}
			}
			
		}
	}

	


}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	DrawRectangle(static_cast<int>(player->getPos().x), static_cast<int>(player->getPos().y), static_cast<int>(player->getSize().x), static_cast<int>(player->getSize().y), BLUE);
	DrawCircleV(ball->getPos(), static_cast<float>(ball->getRadius()), RED);


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
