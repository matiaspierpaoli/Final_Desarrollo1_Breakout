#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
	size = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenHeight()) / 15 };
	pos = { static_cast<float>(GetScreenWidth()) / 2 - size.x / 2,static_cast<float>(GetScreenHeight()) - size.y - 10 };
	speed = 400;
	lives = 5;
}
