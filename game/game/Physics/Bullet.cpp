#include "Bullet.h"
#include "Server.h"
#include <random>
#include "Splinter.cpp"

namespace
{
	const float ExplosionHeight{ 100 };
	const unsigned int SplintersCount{ 100 };
}

namespace Physics
{
	Bullet::~Bullet()
	{
	}

	void Bullet::onFrame(float dt)
	{
		if (isExploded)
			ProcessSplinter(dt);
		else
			ProcessBullet(dt);
	}
	void Bullet::ProcessBullet(float dt)
	{
		bulletY += bulletVY * dt;
		bulletVY -= (g*dt);

		if (bulletY > ExplosionHeight)
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
			std::uniform_int_distribution<> distr(-bulletVY, bulletVY);
			auto spVX = distr(gen);
			std::uniform_int_distribution<> distr(-sqrt(pow(bulletVY, 2) - pow(spVX, 2)), sqrt(pow(bulletVY, 2) - pow(spVX, 2)));
			auto spVY = distr(gen);
			splinters.emplace_back(bulletX, bulletY, spVX, spVY);
		}
		isExploded = true;
	}
	
}
