#include "server.h"
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
			splinterY += splinterVY * dt;
			splinterVY -= (g * dt);
			splinterX += splinterVX * dt;
		}
	}
}