#include "Brick.h"

Brick::Brick()
{

	color = GetRandomValue(0, 4);
	size = { static_cast<float>(GetScreenWidth()) / 10 ,
			static_cast<float>(GetScreenHeight()) / 10 };
	active = true;

}

Brick::~Brick()
{
}

void Brick::locate(int x, int y)
{

}
