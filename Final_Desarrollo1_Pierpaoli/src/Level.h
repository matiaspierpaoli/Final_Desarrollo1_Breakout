#pragma once
#include "Brick.h"

class Level
{
private:

public:
	Level();
	~Level();

	void setMapLevel1(int rows, int columns, Brick *bricks[][6], Texture2D redBrickTexture, 
																 Texture2D orangeBrickTexture, 
																 Texture2D yellowBrickTexture, 
																 Texture2D greenBrickTexture, 
																 Texture2D skyblueBrickTexture, 
																 Texture2D blueBrickTexture);
	void setMapLevel2();
	void setMapLevel3();
};
