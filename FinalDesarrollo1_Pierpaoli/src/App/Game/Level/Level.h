#pragma once
#include "..\GamePlayElements\Brick\Brick.h"

namespace BreakoutGame
{
	class Level
	{
	public:
		Level();
		~Level();

		void setMapLevel1(int rows, int columns, Brick* bricks[][6]);
	};
}