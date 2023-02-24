#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::setMapLevel1(int rows, int columns, Brick* bricks[][6], Texture2D redBrickTexture,
																	Texture2D orangeBrickTexture,
																	Texture2D yellowBrickTexture,
																	Texture2D greenBrickTexture,
																	Texture2D skyblueBrickTexture,
																	Texture2D blueBrickTexture)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			bricks[i][j]->setPos(i * bricks[i][j]->getSize().x,
								 j * bricks[i][j]->getSize().y);

			//bricks[i][j]->setColor(j);

			switch (j)
			{
			case 0:
				bricks[i][j]->setTexture(redBrickTexture);
				break;
			case 1:
				bricks[i][j]->setTexture(orangeBrickTexture);
				break;
			case 2:
				bricks[i][j]->setTexture(yellowBrickTexture);
				break;
			case 3:
				bricks[i][j]->setTexture(greenBrickTexture);
				break;
			case 4:
				bricks[i][j]->setTexture(skyblueBrickTexture);
				break;
			case 5:
				bricks[i][j]->setTexture(blueBrickTexture);
				break;
			default:
				break;
			}
		}
	}
}
