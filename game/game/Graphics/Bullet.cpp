#include "Bullet.h"
#include "Server.h"
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <cassert>

namespace Graphics
{
	Bullet::Bullet(graphServer& Server) : Entity(Server)
	{
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::onFrame(float dt)
	{
	}
	
	void Bullet::setSplinterPosition(int index, float x, float y)
	{
		if (splinters.size() > index)
		{
			splinters[index].x = x;
			splinters[index].y = y;
		}
		else
		{
			assert(index == splinters.size());
			splinters.emplace_back(x, y);
		}
	}
}