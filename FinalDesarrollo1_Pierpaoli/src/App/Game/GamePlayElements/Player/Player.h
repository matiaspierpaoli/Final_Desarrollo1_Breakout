#pragma once
#include "raylib.h"

namespace BreakoutGame
{
	class Player
	{
	private:
		Vector2 pos;
		Vector2 size;
		int normalSpeed; // Velocidad original
		int speed; // Velocidad cambiante
		int lives;
		int points;
		int currentBricksDestroyed;

		Texture2D texture;

	public:
		Player(Vector2 size, int normalSpeed, int lives, Texture2D texture);
		~Player();

		void setPos(float x, float y);
		void setSize(float x, float y);
		void setSpeed(int speed);
		void setLives(int lives);
		void setTexture(Texture2D texture);
		void setPoints(int points);
		void setCurrentBricksDestroyed(int currentBricksDestroyed);

		void reduceLive();
		void addLife();

		Vector2 getPos();
		Vector2 getSize();
		int getLives();
		int getNormalSpeed();
		int getPoints();
		int getCurrentBricksDestroyed();

		void Reset();

		void moveLeft();
		void moveRight();

		void Draw();
	};
}