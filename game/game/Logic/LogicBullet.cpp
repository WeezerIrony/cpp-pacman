#include "LogicBullet.h"
#include "LogicServer.h"
#include "Physics/PhysicsBullet.h"
#include "Graphics/GraphicsBullet.h"

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

	void Bullet::updateGraphics()
	{
		gbullet->setRenderType(!pbullet->GetExplode());
		if (!pbullet->GetExplode())
		{
			gbullet->setRocketPosition(pbullet->GetCoords().first, pbullet->GetCoords().second);
		}
		else
		{
			int index{ 0 };
			for (auto &&splinter : pbullet->GetSplinters())
			{
				gbullet->setSplinterPosition(index, splinter.GetCoords().first, splinter.GetCoords().second);
				index++;
			}
		}
	}

	void Bullet::OnFrame(float dt)
	{
		if (pbullet->IsOnGround())
		{
			m_server.RegisterDeleteEntity(this);
		}
		else
		{
			updateGraphics();
		}
	}
}