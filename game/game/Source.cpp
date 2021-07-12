#include "Core/Application.h"

int main()
{
	auto IServer = new Input::inServer;
	auto PServer = new Physics::physServer;
	auto LServer = new Logic::logServer;
	auto GServer = new Graphics::graphServer(IServer);
	Application app(PServer, LServer, GServer, IServer);
	if (app.Activate())
	{
		app.Run();
	}
	app.Deactivate();

	return 0;
}