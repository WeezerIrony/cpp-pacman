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
		splinterY += splinterVY * dt;
		splinterVY -= (g*dt);
		splinterX += splinterVX * dt;
	}
}