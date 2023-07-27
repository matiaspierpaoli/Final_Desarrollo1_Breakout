#include "Game.h"

Game::Game(SceneManager* sceneManager, Music musicRef)
{
	this->sceneManager = sceneManager; // manager de game = manager de app
	this->musicRef = musicRef;

	// Efectos de sonido
	ballSound = { NULL };
	defeatSound = { NULL };
	victorySound = { NULL };

	// Texturas
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

	victoryScreenTexture = { NULL };
	defeatScreenTexture = { NULL };


	// Random para la activacion de powerUps
	rndPowerUpActivation = 0;

	// Booleanos
	win = false;
	pause = false;
	isMusicMuted = false;

	muteStartTime = 0;
	musicMuteDuration = 3;

	currentTime = 0;
	timer = 0.0f;

	baseScore = 1;
	timeMultiplier = 1.0;
	penaltyDivisionFactor = 100.0f;
	timeBonusFactor = 0.5;
	maxTimeMultiplier = 2.0;

	highscore = LoadHighscore();

	// Objetos
	player = { NULL };
	ball = { NULL };
	level = { NULL };

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			bricks[i][j] = { NULL };
		}
	}
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

	UnloadTexture(victoryScreenTexture);
	UnloadTexture(defeatScreenTexture);
}

void Game::Init()
{
	// Inicializacion de objetos, booleanos, sonidos y texturas

	win = false;
	pause = false;

	ballSound = LoadSound("res/ballSound.mp3");
	defeatSound = LoadSound("res/defeatSound.mp3");
	victorySound = LoadSound("res/victorySound.mp3");

	redBrickTexture = LoadTexture("res/bricks/redBrick.png");
	orangeBrickTexture = LoadTexture("res/bricks/orangeBrick.png");
	yellowBrickTexture = LoadTexture("res/bricks/yellowBrick.png");
	greenBrickTexture = LoadTexture("res/bricks/greenBrick.png");
	skyblueBrickTexture = LoadTexture("res/bricks/skyblueBrick.png");
	blueBrickTexture = LoadTexture("res/bricks/blueBrick.png");

	addLifeTexture = LoadTexture("res/powerUps/addLife.png");
	reduceLifeTexture = LoadTexture("res/powerUps/reduceLife.png");
	addSpeedTexture = LoadTexture("res/powerUps/addSpeed.png");
	reduceSpeedTexture = LoadTexture("res/powerUps/reduceSpeed.png");

	ballTexture = LoadTexture("res/ball.png");
	playerTexture = LoadTexture("res/player.png");

	victoryScreenTexture = LoadTexture("res/screens/victoryScreen.png");
	defeatScreenTexture = LoadTexture("res/screens/defeatScreen.png");

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

	player = new Player({ static_cast<float>(GetScreenWidth()) / 6, static_cast<float>(GetScreenHeight()) / 30 }, 500, 5, playerTexture);
	ball = new Ball({ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, { 0,0 }, 20, false, ballTexture);
	level = new Level();
	level->setMapLevel1(rows, columns, bricks); // Armado de mapa (ubicacion de ladrillos)

	powerUps.push_back(new PowerUp({ 0,0 }, { 36, 36 }, false, TypeOfPowerUp::AddLife, addLifeTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { 36, 36 }, false, TypeOfPowerUp::SubstractLife, reduceLifeTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { 36, 36 }, false, TypeOfPowerUp::MultiplyPlayerSpeed, addSpeedTexture));
	powerUps.push_back(new PowerUp({ 0,0 }, { 36, 36 }, false, TypeOfPowerUp::SLowPlayerDown, reduceSpeedTexture));

	for (int i = 0; i < powerUps.size(); i++)
	{
		// Nueva posicion sin colisionar con player y ball
		powerUps[i]->setNewRndPos(player->getPos(), player->getSize(), { ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, ball->getRadius(), columns * bricks[0][0]->getSize().y, linePosY);
	}
}

void Game::Input()
{
	if (!win)
	{
		if (IsKeyPressed(KEY_P)) pause = !pause; // Activacion/Desactivacion de pausa

		if (!pause)
		{
			// Activate Ball
			if (!ball->getActive())
			{
				if (IsKeyPressed(KEY_SPACE)) // Activacion de bola
				{
					ball->setActive(true);
					ball->setSpeed({ static_cast<float>(GetRandomValue(-GetScreenWidth() / 2, GetScreenWidth() / 2)), -300 });
				}
			}

			// Movimiento de Jugador
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
				player->moveLeft();
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
				player->moveRight();
		}
		else
		{
			if (IsKeyPressed(KEY_M)) // Si en pausa se presiona M se vuelve al menu habiendo reseteado posiciones y booleanos
			{
				pause = false;
				sceneManager->setScene(Scene::MENU);
				Reset();
			}
		}
	}
	else
	{
		if (IsKeyPressed(KEY_M)) // Si al terminar el juego se presiona M se vuelve al menu habiendo reseteado posiciones y booleanos
		{
			pause = false;
			sceneManager->setScene(Scene::MENU);
			Reset();
			SetMusicVolume(musicRef, 0.2f);
		}

		if (IsKeyPressed(KEY_R)) // Si al terminar el juego se presiona R se vuelve a jugar habiendo reseteado posiciones y booleanos
		{
			pause = false;
			win = false;
			Reset();
			SetMusicVolume(musicRef, 0.2f);
		}
	}

}

void Game::Update()
{
	if (!win)
	{
		if (!pause)
		{					
 			timer += GetFrameTime();
			if (timer >= 1.0f)
			{
				currentTime += static_cast<int>(timer);
				timer = 0;
			}
			
			// Activacion de PowerUp
			rndPowerUpActivation = GetRandomValue(0, 800);

			// El switch mas dudoso jaja
			switch (rndPowerUpActivation) // 1 chance en 800 para cada powerUp (siendo 60 por segundo)
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

			// Movimiento de Bola
			if (ball->getActive())
				ball->move();
			else
				ball->setSpeed({ player->getPos().x + player->getSize().x / 2, player->getPos().y - ball->getRadius() });

			// -----------------------------------  Colisiones de Bola -------------------------------------------------------------------
			// Bola - Bordes de pantalla
			if (ball->checkCollisionWithWalls(linePosY)) // Unicamente entra al if si colisiona con la linea inferior a jugador
			{
				ball->reset();
				player->reduceLive();
			}

			// Bola - Jugador
			ball->checkCollisionWithPlayer(player->getPos(), player->getSize(), ballSound);

			// Bola - Ladrillos
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (bricks[i][j]->getActive()) // Si el ladrillo esta activo
					{
						// Circle-Rec de raylib
						if (CheckCollisionCircleRec(ball->getPos(), static_cast<float>(ball->getRadius()), { bricks[i][j]->getPos().x, bricks[i][j]->getPos().y, bricks[i][j]->getSize().x, bricks[i][j]->getSize().y }))
						{
							bricks[i][j]->setActive(false);
							ball->changeYDirection(); // Cambio de direccion en y
							player->setCurrentBricksDestroyed(player->getCurrentBricksDestroyed() + 1); // 1 ladrillo destruido
						}
					}
				}
			}

			// Bola - PowerUp 
			for (int i = 0; i < powerUps.size(); i++)
			{
				if (powerUps[i]->getActive())
				{
					// Circle - Rec de raylib
					if (CheckCollisionCircleRec({ ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, static_cast<float>(ball->getRadius()), { powerUps[i]->getPos().x, powerUps[i]->getPos().y, powerUps[i]->getSize().x,powerUps[i]->getSize().y }))
					{
						powerUps[i]->setActive(false);
						// Nueva posicion
						powerUps[i]->setNewRndPos(player->getPos(), player->getSize(), { ball->getPos().x + ball->getRadius(), ball->getPos().y + ball->getRadius() }, ball->getRadius(), columns * bricks[0][0]->getSize().y, linePosY);

						switch (powerUps[i]->getTypeOfPowerUp())
						{
						case TypeOfPowerUp::AddLife:
							player->addLife(); // Se agrega una vida al jugador
							break;
						case TypeOfPowerUp::SubstractLife:
							player->reduceLive(); // Se resta una vida al jugador
							break;
						case TypeOfPowerUp::MultiplyPlayerSpeed:
							player->setSpeed(player->getNormalSpeed() * 2); // Se multiplica la velocidad por 2 al jugador
							break;
						case TypeOfPowerUp::SLowPlayerDown:
							player->setSpeed(player->getNormalSpeed() - player->getNormalSpeed() / 10); // Se divide la velocidad por la diferencia del total menos el 10% al jugador
							break;
						default:
							break;
						}
					}
				}
			}

			if (player->getLives() == 0) // Si la vida del jugador llega a 0
			{
				SetMusicVolume(musicRef, 0.0f);
				win = !win;
				PlaySound(defeatSound);
				isMusicMuted = true;
				muteStartTime = GetTime();
			}

			if (player->getCurrentBricksDestroyed() >= rows * columns) // Si llega a desactivar todos los ladrillos
			{
				SetMusicVolume(musicRef, 0.0f);
				win = !win;
				PlaySound(victorySound);
				isMusicMuted = true;
				muteStartTime = GetTime();
			}
		}
	}
	else
	{
		if (isMusicMuted && (GetTime() - muteStartTime) >= musicMuteDuration) // Se retoma luego de una duracion definida la musica
		{
			isMusicMuted = false;
			SetMusicVolume(musicRef, 0.2f); // Restore the music volume
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	if (!win) // Si el juego sigue activo
	{
		player->Draw();
		ball->Draw();

		DrawLine(startLinePosX, linePosY, endLinePosX, linePosY, BLACK); // Linea inferior al jugador

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

		// Vidas
		DrawText(TextFormat("Lives: %4i", player->getLives()), 5, static_cast<int>(GetScreenHeight() - 40), 40, DARKGREEN);
		// Tiempo Actual
		DrawText(TextFormat("Time: %4i", static_cast<int>(currentTime)), static_cast<int>(GetScreenWidth() - 250), static_cast<int>(GetScreenHeight() - 40), 40, DARKGREEN);

		if (pause) // Si pausa == true
		{
			DrawText(TextFormat("Press P to unpause"), static_cast<int>(GetScreenWidth() / 2) - 190, static_cast<int>(GetScreenHeight() / 2) + 20, 40, RED);
			DrawText(TextFormat("Press M to go back to menu"), static_cast<int>(GetScreenWidth() / 2) - 250, static_cast<int>(GetScreenHeight() / 2) + 70, 40, RED);
		}
	}
	else // Si termino el juego
	{
		if (player->getCurrentBricksDestroyed() < rows * columns)
		{
			DrawTexture(defeatScreenTexture, 0, 0, WHITE); // Derrota
			DrawText(TextFormat("Points: %4i", player->getPoints()), static_cast<int>(GetScreenWidth() / 2 - 100), static_cast<int>(GetScreenHeight() / 2 - 40), 40, WHITE);
			DrawText(TextFormat("Highscore: %4i", highscore), static_cast<int>(GetScreenWidth() / 2 - 150), static_cast<int>(GetScreenHeight() / 2 - 10), 40, WHITE);
		}
		else
		{
			DrawTexture(victoryScreenTexture, 0, 0, WHITE); // Victoria
			DrawText(TextFormat("Points: %4i", player->getPoints()), static_cast<int>(GetScreenWidth() / 2 - 100), static_cast<int>(GetScreenHeight() / 2 - 40), 40, BLACK);
			DrawText(TextFormat("Highscore: %4i", highscore), static_cast<int>(GetScreenWidth() / 2 - 150), static_cast<int>(GetScreenHeight() / 2 - 10), 40, BLACK);

		}

		CalculateScore();
	}

	EndDrawing();
}

void Game::DeInit()
{
	// Quitar efectos de sonido
	UnloadSound(ballSound);
	UnloadSound(victorySound);
	UnloadSound(defeatSound);

	// Quitar texturas
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
	UnloadTexture(victoryScreenTexture);
	UnloadTexture(defeatScreenTexture);

	// Eliminacion de espacio en el heap
	delete player;
	delete ball;
	delete level;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			delete bricks[i][j];
		}
	}

	for (auto&& powerUps : powerUps) // Eliminacion de vector en for automactico
	{
		delete powerUps;
	}
	powerUps.clear();
}

void Game::CalculateScore()
{
	double timeMultiplier = maxAllowedTime / currentTime;
	timeMultiplier += (1.0 - timeMultiplier) * timeBonusFactor;
	timeMultiplier = fmin(timeMultiplier, maxTimeMultiplier);
	
	double finalMultiplier = timeMultiplier * player->getCurrentBricksDestroyed();
	
	if (player->getLives() > 0)
		finalMultiplier *= player->getLives();

	player->setPoints(baseScore * finalMultiplier);

	if (player->getPoints() > highscore)
	{
		highscore = player->getPoints();
		SaveHighscore(highscore);
	}
}

void Game::SaveHighscore(int highscore)
{
	std::ofstream outputFile("./highscore.bin", std::ios::binary);
	if (outputFile.is_open())
	{
		outputFile.write(reinterpret_cast<const char*>(&highscore), sizeof(highscore));
		outputFile.close();
	}
}

int Game::LoadHighscore()
{
	int highscore = 0;
	std::ifstream inputFile("./highscore.bin", std::ios::binary);
	if (inputFile.is_open())
	{
		inputFile.read(reinterpret_cast<char*>(&highscore), sizeof(highscore));
		inputFile.close();
	}
	return highscore;
}

void Game::Reset()
{
	player->Reset();
	ball->reset();

	win = false;
	pause = false;

	currentTime = 0;
	timer = 0.0f;

	timeMultiplier = 1.0;

	for (int i = 0; i < powerUps.size(); i++)
	{
		powerUps[i]->setActive(false);
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			bricks[i][j]->setActive(true);
		}
	}
}