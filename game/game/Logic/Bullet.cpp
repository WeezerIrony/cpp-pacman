#include "Bullet.h"
#include "Server.h"
#include "Physics/Bullet.h"
#include "Graphics/Bullet.h"

namespace Logic
{
	Bullet::Bullet(logServer& Server, Physics::Bullet* pb, Graphics::Bullet* gb) : Entity(Server)
	{
		pbullet = pb;
		gbullet = gb;
	}

	Bullet::~Bullet()
	{
		delete pbullet;
		delete gbullet;
	}

	void Bullet::onFrame(float dt)
	{
	}
}