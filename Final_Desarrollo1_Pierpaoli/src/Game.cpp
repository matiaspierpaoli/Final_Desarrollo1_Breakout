#include "Game.h"

Game::Game(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	ballSound = { NULL };
	defeatSound = { NULL };
	victorySound = { NULL };

	redBrickTexture = { NULL };
	orangeBrickTexture = { NULL };
	yellowBrickTexture = { NULL };
	greenBrickTexture = { NULL };
	skyblueBrickTexture = { NULL };
	blueBrickTexture = { NULL };

	ballTexture = { NULL };
	playerTexture = { NULL };

	rndPowerUpActivation = 0;
}

Game::~Game()
{
	UnloadTexture(redBrickTexture);
	UnloadTexture(orangeBrickTexture);
	UnloadTexture(yellowBrickTexture);
	UnloadTexture(greenBrickTexture);
	UnloadTexture(skyblueBrickTexture);
	UnloadTexture(blueBrickTexture);
	UnloadTexture(ballTexture);
	UnloadTexture(playerTexture);
}

void Game::Init()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			bricks[i][j] = new Brick();
			bricks[i][j]->setSize(GetScreenWidth() / rows, GetScreenHeight() / 20);
		}
	}

	/*for (int i = 0; i < powerUps.size(); i++)
	{
		switch (powerUps[i]->getTypeOfPowerUp())		
		{
		case TypeOfPowerUp::AddLife:
			powerUps[i]->setTexture();
			break;
		case TypeOfPowerUp::SubstractLife:
			powerUps[i]->setTexture();
			break;
		case TypeOfPowerUp::MultiplyBall:
			powerUps[i]->setTexture();
			break;
		case TypeOfPowerUp::SLowPlayerDown:
			powerUps[i]->setTexture();
			break;
		default:
			break;
		}
	}*/

	win = false;
	points = 0;
	pause = false;

	ballSound = LoadSound("../res/ballSound.mp3");
	defeatSound = LoadSound("../res/defeatSound.mp3");
	victorySound = LoadSound("../res/victorySound.mp3");

	redBrickTexture = LoadTexture("../res/bricks/redBrick.png");
	orangeBrickTexture = LoadTexture("../res/bricks/orangeBrick.png");
	yellowBrickTexture = LoadTexture("../res/bricks/yellowBrick.png");
	greenBrickTexture = LoadTexture("../res/bricks/greenBrick.png");
	skyblueBrickTexture = LoadTexture("../res/bricks/skyblueBrick.png");
	blueBrickTexture = LoadTexture("../res/bricks/blueBrick.png");

	ballTexture = LoadTexture("../res/ball.png");
	playerTexture = LoadTexture("../res/player.png");

	player = new Player();
	player->setTexture(playerTexture);

	level = new Level();
	level->setMapLevel1(rows, columns, bricks, redBrickTexture, orangeBrickTexture, yellowBrickTexture, greenBrickTexture, skyblueBrickTexture, blueBrickTexture);

	ball = new Ball({ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, {0,0}, 20, false, ballTexture);
	
	Vector2 newSize;
	newSize.x = 5;
	newSize.y = 5;

	powerUps.push_back(new PowerUp({0,0}, { newSize }, false, TypeOfPowerUp::AddLife));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, false, TypeOfPowerUp::SubstractLife));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, false, TypeOfPowerUp::MultiplyBall));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, false, TypeOfPowerUp::SLowPlayerDown));

	for (int i = 0; i < powerUps.size(); i++)
	{
		powerUps[i]->setNewRndPos(player->getPos(), player->getSize(), { ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, ball->getRadius(), columns * bricks[0][0]->getSize().y, linePosY);
	}
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
			// PowerUp activation
			rndPowerUpActivation = GetRandomValue(0, 800);

			switch (rndPowerUpActivation)
			{
			case 0:
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::AddLife)
						powerUps[i]->setActive(true);
				}
				break;
			case 200:
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::SubstractLife)
						powerUps[i]->setActive(true);
				}
				break;
			case 400:
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::MultiplyBall)
						powerUps[i]->setActive(true);
				}
				break;
			case 600:
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::SLowPlayerDown)
						powerUps[i]->setActive(true);
				}
				break;
			case 800:
				for (int i = 0; i < powerUps.size(); i++)
				{
					powerUps[i]->setActive(true); // Activate all powerUps
				}
				break;
			default:
				break;
			}

			// Ball Movement
			if (ball->getActive())
				ball->move();
			else
				ball->setSpeed({ player->getPos().x + player->getSize().x / 2, player->getPos().y - ball->getRadius() });


			// Ball - Walls collisions
			if (ball->checkCollisionWithWalls(linePosY)) // Only true if ball hits line below player
			{
				ball->reset();
				player->reduceLive();
			}

			// Ball - Player collisions
			ball->checkCollisionWithPlayer(player->getPos(), player->getSize(), ballSound);
				

			// Ball - Bricks collisions
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (bricks[i][j]->getActive())
					{
						if (CheckCollisionCircleRec(ball->getPos(), static_cast<float>(ball->getRadius()), { bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y }))
						{
							bricks[i][j]->setActive(false);
							ball->changeYDirection();
							points += 1;
						}
					}

				}
			}

			// Ball - PowerUp collision
			for (int i = 0; i < powerUps.size(); i++)
			{
				if (powerUps[i]->getActive())
				{
					if (CheckCollisionCircleRec({ ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, static_cast<float>(ball->getRadius()), { powerUps[i]->getPos().x, powerUps[i]->getPos().y, powerUps[i]->getSize().x,powerUps[i]->getSize().y }))
					{
						powerUps[i]->setActive(false);

						switch (powerUps[i]->getTypeOfPowerUp())
						{
						case TypeOfPowerUp::AddLife:
							player->addLife();
							break;
						case TypeOfPowerUp::SubstractLife:
							player->reduceLive();
							break;
						case TypeOfPowerUp::MultiplyBall:
							break;
						case TypeOfPowerUp::SLowPlayerDown:
							break;
						default:
							break;
						}
					}
				}

				


			}

			if (player->getLives() == 0)
			{
				win = !win;
				PlaySound(defeatSound);
			}

			if (points >= rows * columns)
			{
				win = !win;
				PlaySound(victorySound);
			}
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	if (!win)
	{
		//DrawRectangle(static_cast<int>(player->getPos().x), static_cast<int>(player->getPos().y), static_cast<int>(player->getSize().x), static_cast<int>(player->getSize().y), BLUE);
		player->Draw();
		ball->Draw();

		DrawLine(startLinePosX, linePosY, endLinePosX, linePosY, BLACK);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (bricks[i][j]->getActive())				
					bricks[i][j]->Draw();			
			}
		}

		for (int i = 0; i < powerUps.size(); i++)
		{
			if (powerUps[i]->getActive())
				powerUps[i]->Draw();
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
	UnloadSound(ballSound);
	UnloadSound(victorySound);
	UnloadSound(defeatSound);

	UnloadTexture(redBrickTexture);
	UnloadTexture(orangeBrickTexture);
	UnloadTexture(yellowBrickTexture);
	UnloadTexture(greenBrickTexture);
	UnloadTexture(skyblueBrickTexture);
	UnloadTexture(blueBrickTexture);
	UnloadTexture(ballTexture);
	UnloadTexture(playerTexture);

	delete player;
	delete ball;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			delete bricks[i][j];
		}
	}

	powerUps.clear();

	delete level;
}
