#include "Player.h"

namespace BreakoutGame
{
	Player::Player(Vector2 _size, int _normalSpeed, int _lives, Texture2D _texture)
	{
		size = _size;
		normalSpeed = _normalSpeed;
		speed = normalSpeed;
		lives = _lives;
		texture = _texture;
		points = 0;
		currentBricksDestroyed = 0;

		setPos(GetScreenWidth() / 2 - size.x / 2, GetScreenHeight() - size.y - 60);
	}

	Player::~Player()
	{

	}

	void Player::setPos(float _x, float _y)
	{
		pos.x = _x;
		pos.y = _y;
	}

	void Player::setSize(float _x, float _y)
	{
		size.x = _x;
		size.y = _y;
	}

	void Player::setSpeed(int _speed)
	{
		speed = _speed;
	}

	void Player::setLives(int _lives)
	{
		lives = _lives;
	}

	void Player::setTexture(Texture2D _texture)
	{
		texture = _texture;
	}

	void Player::setPoints(int _points)
	{
		points = _points;
	}

	void Player::setCurrentBricksDestroyed(int _currentBricksDestroyed)
	{
		currentBricksDestroyed = _currentBricksDestroyed;
	}

	void Player::reduceLive()
	{
		lives -= 1;

		if (lives <= 0)
			lives = 0;
	}

	void Player::addLife()
	{
		lives++;
	}

	Vector2 Player::getPos()
	{
		return pos;
	}

	Vector2 Player::getSize()
	{
		return size;
	}

	int Player::getLives()
	{
		return lives;
	}

	int Player::getNormalSpeed()
	{
		return normalSpeed;
	}

	int Player::getPoints()
	{
		return points;
	}

	int Player::getCurrentBricksDestroyed()
	{
		return currentBricksDestroyed;
	}

	void Player::Reset()
	{
		lives = 5;
		points = 0;
		currentBricksDestroyed = 0;
		speed = normalSpeed;
		setPos(static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) - size.y - 60);
	}

	void Player::moveLeft()
	{
		if (pos.x > 0)
		{
			pos.x -= GetFrameTime() * speed;
		}
	}

	void Player::moveRight()
	{
		if (pos.x + size.x <= GetScreenWidth())
		{
			pos.x += GetFrameTime() * speed;
		}
	}

	void Player::Draw()
	{
		DrawTexture(texture, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
	}
}