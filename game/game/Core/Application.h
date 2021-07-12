#pragma once
#include "Physics/PhysicsServer.h"
#include "Graphics/GraphicsServer.h"
#include "Logic/LogicServer.h"
#include "Input/InputServer.h"


class Application final
{
public:
    explicit Application(Physics::physServer* P, Logic::logServer* L, Graphics::graphServer* G, Input::inServer* I) : PhysServer(P), LogServer(L), GraphServer(G), InpServer(I) {};
    ~Application();

    bool Activate();
    void Run() const;
    void Deactivate();

private:
    void HandleEvents() const;
    Physics::physServer* PhysServer{ nullptr };
    Logic::logServer* LogServer{ nullptr };
    Graphics::graphServer* GraphServer{ nullptr };
    Input::inServer* InpServer{ nullptr };


friend class ApplicationBuilder;
};