#include "PowerUp.h"

PowerUp::PowerUp()
{
	texture = { NULL };
}

PowerUp::~PowerUp()
{

}

inline void PowerUp::setPos(Vector2 pos)
{
	this->pos = pos;
}

inline void PowerUp::setSize(Vector2 size)
{
	this->size = size;
}

inline void PowerUp::setActive(bool active)
{
	this->active = active;
}

inline void PowerUp::setTexture(Texture2D texture)
{
	this->texture = texture;
}

inline Vector2 PowerUp::getPos()
{
	return pos;
}

inline Vector2 PowerUp::getSize()
{
	return size;
}

inline bool PowerUp::getActive()
{
	return active;
}

inline Texture2D PowerUp::getTexture()
{
	return texture;
}

inline void PowerUp::Draw()
{

}