#pragma once
#include "Command.h"
#include "Physics/PhysicsBullet.h"
#include "Logic/Firework/LogicBullet.h"
#include "Graphics/GraphicsBullet.h"
#include "Input/InputServer.h"


class CreateBullet : public Command
{
public:
    explicit CreateBullet(Physics::physServer* P, Logic::logServer* L, Graphics::graphServer* G, Input::inServer* I) : CommPhysServer(P), CommLogServer(L), CommGraphServer(G), CommInpServer(I) {};
    void Execute() const override;

private:
    Physics::physServer* CommPhysServer{ nullptr };
    Logic::logServer* CommLogServer{ nullptr };
    Graphics::graphServer* CommGraphServer{ nullptr };
    Input::inServer* CommInpServer{ nullptr };
};