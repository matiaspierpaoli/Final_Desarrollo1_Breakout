#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::setMapLevel1(int rows, int columns, Brick* bricks[][6])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			bricks[i][j]->setPos(i * bricks[i][j]->getSize().x,
								 j * bricks[i][j]->getSize().y);
		}
	}
}
