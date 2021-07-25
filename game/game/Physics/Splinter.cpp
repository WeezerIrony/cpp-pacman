#include "PhysicsServer.h"
#include "Splinter.h"

namespace
{
	const float g{ 10 };
}

namespace Physics 
{
	void Splinter::Simulate(float dt)
	{
		if (!SplinterOnGround())
		{
			InAir(dt);
		}
		else
		{
			OnGround();
		}
	}

	void Splinter::InAir(float dt)
	{
		if (splinterPosition.y >= splinterBox.ys)
		{
			splinterVelocity.y *= -1;
		}

		if (splinterPosition.x >= splinterBox.xs)
		{
			splinterVelocity.x *= -1;
		}

		if (splinterPosition.x <= splinterBox.x0)
		{
			splinterVelocity.x *= -1;
		}

		splinterPosition.y += splinterVelocity.y * dt;
		splinterVelocity.y -= (g * dt);
		splinterPosition.x += splinterVelocity.x * dt;
		splinterPosition.z += splinterVelocity.z * dt;
	}

	void Splinter::OnGround()
	{
		splinterVelocity.x = 0;
		splinterVelocity.y = 0;
		splinterVelocity.z = 0;
	}
}