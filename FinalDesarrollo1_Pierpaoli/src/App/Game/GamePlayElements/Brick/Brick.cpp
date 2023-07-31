#include "Brick.h"

namespace BreakoutGame
{
	Brick::Brick(Vector2 _pos, Vector2 _size, bool _active, Texture2D _texture)
	{
		pos = _pos;
		size = _size;
		active = _active;
		texture = _texture;
	}

	Brick::~Brick()
	{

	}

	void Brick::setPos(int _x, int _y)
	{
		pos.x = static_cast<float>(_x);
		pos.y = static_cast<float>(_y);
	}

	void Brick::setSize(int _x, int _y)
	{
		size.x = static_cast<float>(_x);
		size.y = static_cast<float>(_y);
	}

	void Brick::setActive(bool _active)
	{
		active = _active;
	}

	void Brick::setTexture(Texture2D _texture)
	{
		texture = _texture;
	}

	Vector2 Brick::getPos()
	{
		return pos;
	}

	Vector2 Brick::getSize()
	{
		return size;
	}

	bool Brick::getActive()
	{
		return active;
	}

	void Brick::Draw()
	{
		DrawTexture(texture, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
	}
}