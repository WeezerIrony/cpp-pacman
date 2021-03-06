#include "PhysicsBullet.h"
#include "PhysicsServer.h"
#include <random>

namespace
{
	const float g{ 10 };
	const float ExplosionHeight{ 600 };
	const unsigned int SplintersCount{ 100 };
}

namespace Physics
{
	Bullet::~Bullet()
	{
	}

	void Bullet::OnFrame(float dt)
	{
		if (isExploded)
			ProcessSplinter(dt);
		else
			ProcessBullet(dt);
	}
	void Bullet::ProcessBullet(float dt)
	{
		bulletPosition.y += bulletVY * dt;
		bulletVY -= (g*dt);

		if (bulletPosition.y > ExplosionHeight)
			Explode();
	}

	void Bullet::ProcessSplinter(float dt)
	{
		SplintersOnGround = true;
		for (Splinter& splinter : splinters)
		{
			splinter.Simulate(dt);
			SplintersOnGround &= splinter.SplinterOnGround();
		}
	}

	void Bullet::Explode()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		for (int i{ 0 }; i < SplintersCount; i++)
		{
			std::uniform_int_distribution<> distr1(-bulletVY, bulletVY);
			float spVX = distr1(gen);
			std::uniform_int_distribution<> distr2(-sqrt(pow(bulletVY, 2) - pow(spVX, 2)), sqrt(pow(bulletVY, 2) - pow(spVX, 2)));
			float spVY = distr2(gen);
			std::uniform_int_distribution<> distr3(-sqrt(pow(bulletVY, 2) - pow(spVX, 2) - pow(spVY, 2)), sqrt(pow(bulletVY, 2) - pow(spVX, 2) - pow(spVY, 2)));
			float spVZ = distr3(gen);
			const Core::vector3& velocity{ spVX, spVY, spVZ };
			splinters.emplace_back(bulletPosition, velocity, m_server.getWorldBox());
		}
		isExploded = true;
	}
	
}
