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

	addLifeTexture = { NULL };
	reduceLifeTexture = { NULL };
	addSpeedTexture = { NULL };
	reduceSpeedTexture = { NULL };

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

	UnloadTexture(addLifeTexture);
	UnloadTexture(reduceLifeTexture);
	UnloadTexture(addSpeedTexture);
	UnloadTexture(reduceSpeedTexture);
}

void Game::Init()
{
	win = false;
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

	addLifeTexture = LoadTexture("../res/powerUps/addLife.png");
	reduceLifeTexture = LoadTexture("../res/powerUps/reduceLife.png");
	addSpeedTexture = LoadTexture("../res/powerUps/addSpeed.png");
	reduceSpeedTexture = LoadTexture("../res/powerUps/reduceSpeed.png");

	ballTexture = LoadTexture("../res/ball.png");
	playerTexture = LoadTexture("../res/player.png");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			switch (j)
			{
			case 0:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, redBrickTexture);
				break;
			case 1:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, orangeBrickTexture);
				break;
			case 2:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, yellowBrickTexture);
				break;
			case 3:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, greenBrickTexture);
				break;
			case 4:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, skyblueBrickTexture);
				break;
			case 5:
				bricks[i][j] = new Brick({ 0,0 }, { static_cast<float>(GetScreenWidth() / rows), static_cast<float>(GetScreenHeight() / 20) }, true, blueBrickTexture);
				break;
			default:
				break;
			}
		}
	}

	player = new Player({ static_cast<float>(GetScreenWidth()) / 6, static_cast<float>(GetScreenHeight()) / 30 }, 500, 5, playerTexture );
	ball = new Ball({ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, { 0,0 }, 20, false, ballTexture);
	level = new Level();
	level->setMapLevel1(rows, columns, bricks);

	Vector2 newSize;
	newSize.x = 36;
	newSize.y = 36;

	powerUps.push_back(new PowerUp({0,0}, { newSize }, true, TypeOfPowerUp::AddLife, addLifeTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, true, TypeOfPowerUp::SubstractLife, reduceLifeTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, true, TypeOfPowerUp::MultiplyPlayerSpeed, addSpeedTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { newSize }, true, TypeOfPowerUp::SLowPlayerDown, reduceSpeedTexture));

	for (int i = 0; i < powerUps.size(); i++)
	{
		powerUps[i]->setNewRndPos(player->getPos(), player->getSize(), { ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius()}, ball->getRadius(), columns * bricks[0][0]->getSize().y, linePosY);
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
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::MultiplyPlayerSpeed)
						powerUps[i]->setActive(true);
					player->setSpeed(player->getNormalSpeed());
				}
			case 600:
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i]->getTypeOfPowerUp() == TypeOfPowerUp::SLowPlayerDown)
						powerUps[i]->setActive(true);
					player->setSpeed(player->getNormalSpeed());
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

			// Original Ball Collisions
			// Ball - Walls
			if (ball->checkCollisionWithWalls(linePosY)) // Only true if ball hits line below player
			{
				ball->reset();
				player->reduceLive();
			}

			// Ball - Player
			ball->checkCollisionWithPlayer(player->getPos(), player->getSize(), ballSound);

			// Ball - Bricks
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
							player->setPoints(player->getPoints() + 1);
						}
					}
				}
			}

			// Ball - PowerUp collision
			for (int i = 0; i < powerUps.size(); i++)
			{
				if (powerUps[i]->getActive())
				{
					// Only check with initial ball
					if (CheckCollisionCircleRec({ ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, static_cast<float>(ball->getRadius()), { powerUps[i]->getPos().x, powerUps[i]->getPos().y, powerUps[i]->getSize().x,powerUps[i]->getSize().y }))
					{
						powerUps[i]->setActive(false);
						powerUps[i]->setNewRndPos(player->getPos(), player->getSize(), { ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, ball->getRadius(), columns * bricks[0][0]->getSize().y, linePosY);

						switch (powerUps[i]->getTypeOfPowerUp())
						{
						case TypeOfPowerUp::AddLife:
							player->addLife();
							break;
						case TypeOfPowerUp::SubstractLife:
							player->reduceLive();
							break;
							case TypeOfPowerUp::MultiplyPlayerSpeed:
							player->setSpeed(player->getNormalSpeed() * 2);
							break;
						case TypeOfPowerUp::SLowPlayerDown:
							player->setSpeed(player->getNormalSpeed() - player->getNormalSpeed() / 10);
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

			if (player->getPoints() >= rows * columns)
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

		// Original Ball
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
			DrawText(TextFormat("Points: %4i", player->getPoints()), GetScreenWidth() - 250, static_cast<int>(GetScreenHeight() - 40), 40, DARKGREEN);
		}
		else
		{
			DrawText(TextFormat("Press P to unpause"), static_cast<int>(GetScreenWidth() / 2) - 190, static_cast<int>(GetScreenHeight() / 2) + 20, 40, RED);
			DrawText(TextFormat("Press M to go back to menu"), static_cast<int>(GetScreenWidth() / 2) - 250, static_cast<int>(GetScreenHeight() / 2) + 70, 40, RED);
		}	
	}
	else
	{
		if (player->getPoints() < rows * columns)
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

	UnloadTexture(addLifeTexture);
	UnloadTexture(reduceLifeTexture);
	UnloadTexture(addSpeedTexture);
	UnloadTexture(reduceSpeedTexture);

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
