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

	win = false;
	points = 0;
	pause = false;
	
}

void Game::Input()
{
	if (!win)
	{
		if (IsKeyPressed(KEY_P)) pause = !pause;

		if (!pause)
		{
			// Activate Ball
			if (!ball->getActive())
			{
				if (IsKeyPressed(KEY_SPACE))
				{
					ball->setActive(true);

					float random = GetRandomValue(-GetScreenWidth() / 2, GetScreenWidth() / 2);
					ball->setSpeed({ random , -300 });
				}
			}

			// Player Movement
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
				player->moveLeft();
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
				player->moveRight();
		}
		else
		{
			if (IsKeyPressed(KEY_M))
			{
				pause = false;
				sceneManager->setScene(Scene::MENU);
				Init();
			}
		}	
	}	
	else
	{
		if (IsKeyPressed(KEY_M))
		{
			pause = false;
			sceneManager->setScene(Scene::MENU);
			Init();
		}

		if (IsKeyPressed(KEY_R))
		{
			pause = false;
			win = false;
			Init();
		}
	}
	
}

void Game::Update()
{
	if (!win)
	{
		if (!pause)
		{
			// Ball Movement
			if (ball->getActive())
				ball->move();
			else
				ball->setSpeed({ player->getPos().x + player->getSize().x / 2, player->getPos().y - ball->getRadius() });


			// Ball - Walls collisions
			if (ball->checkCollisionWithWalls(linePosY)) // Only true if ball hits line below player
			{
				ball->reset();
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
						if (CheckCollisionCircleRec(ball->getPos(), static_cast<float>(ball->getRadius()), { bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y }))
						{
							bricks[i][j]->setState(false);
							ball->changeYDirection();
							points += 1;
						}
					}

				}
			}

			if (player->getLives() == 0)
				win = !win;

			if (points >= rows * columns)
				win = !win;
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	if (!win)
	{
		DrawRectangle(static_cast<int>(player->getPos().x), static_cast<int>(player->getPos().y), static_cast<int>(player->getSize().x), static_cast<int>(player->getSize().y), BLUE);
		DrawCircleV(ball->getPos(), static_cast<float>(ball->getRadius()), RED);

		DrawLine(startLinePosX, linePosY, endLinePosX, linePosY, BLACK);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (bricks[i][j]->getActive())
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

		if (!pause)
		{
			DrawText(TextFormat("Lives: %4i", player->getLives()), 5, static_cast<int>(GetScreenHeight() - 40), 40, DARKGREEN);
		}
		else
		{
			DrawText(TextFormat("Press P to unpause"), static_cast<int>(GetScreenWidth() / 2) - 190, static_cast<int>(GetScreenHeight() / 2) + 20, 40, RED);
			DrawText(TextFormat("Press M to go back to menu"), static_cast<int>(GetScreenWidth() / 2) - 250, static_cast<int>(GetScreenHeight() / 2) + 70, 40, RED);
		}	
	}
	else
	{
		if (points < rows * columns)		
			DrawText(TextFormat("Game Over"), static_cast<int>(GetScreenWidth() / 2) - 100, static_cast<int>(GetScreenHeight() / 2 - 50), 40, RED);		
		else
			DrawText(TextFormat("Victory"), static_cast<int>(GetScreenWidth() / 2) - 100, static_cast<int>(GetScreenHeight() / 2 - 50) , 40, GREEN);

		DrawText(TextFormat("Press R to replay"), static_cast<int>(GetScreenWidth() / 2) - 150, static_cast<int>(GetScreenHeight() / 2) + 20 , 40, RED);
		DrawText(TextFormat("Press M to go back to menu"), static_cast<int>(GetScreenWidth() / 2) - 250, static_cast<int>(GetScreenHeight() / 2) + 70, 40, RED);
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
