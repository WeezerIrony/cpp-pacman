#include "Core/Application.h"

int main()
{
	auto PServer = new Physics::physServer;
	auto LServer = new Logic::logServer;
	auto GServer = new Graphics::graphServer;
	Application app(PServer, LServer, GServer);
	if (app.Activate())
	{
		app.Run();
	}
	app.Deactivate();

	return 0;
}