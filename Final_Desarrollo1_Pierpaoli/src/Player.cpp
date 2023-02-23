#include "Player.h"

Player::Player()
{
	setSize(static_cast<float>(GetScreenWidth()) / 6, static_cast<float>(GetScreenHeight()) / 15);
	setPos(static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) - size.y - 10);
	setSpeed(400);
	setLives(5);
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
