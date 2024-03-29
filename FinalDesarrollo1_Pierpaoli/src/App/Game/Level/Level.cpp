#include "Level.h"

namespace BreakoutGame
{
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
				// Como indica el doble for se ubican primero abajo del anterior 
				bricks[i][j]->setPos(static_cast<int>(i * bricks[i][j]->getSize().x), static_cast<int>(j * bricks[i][j]->getSize().y));
			}
			// Y luego a la derecha
		}
	}
}