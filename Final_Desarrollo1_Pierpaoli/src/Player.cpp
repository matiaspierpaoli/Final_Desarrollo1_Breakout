#include "Player.h"

Player::Player(Vector2 size, int normalSpeed, int lives, Texture2D texture)
{
	this->size = size;
	this->normalSpeed = normalSpeed;
	speed = normalSpeed;
	this->lives = lives;
	this->texture = texture;
	points = 0;

	setPos(static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) - size.y - 60);
}

Player::~Player()
{
	
}

void Player::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Player::setSize(int x, int y)
{
	this->size.x = x;
	this->size.y = y;
}

void Player::setSpeed(int speed)
{
	this->speed = speed;
}

void Player::setLives(int lives)
{
	this->lives = lives;
}

void Player::setTexture(Texture2D texture)
{
	this->texture = texture;
}

void Player::setPoints(int points)
{
	this->points = points;
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

void Player::Reset()
{
	lives = 5;
	points = 0;
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
	DrawTexture(texture, pos.x, pos.y, WHITE);
}


