#pragma once
#include "Command.h"
#include "Physics/PhysicsBullet.h"
#include "Logic/LogicBullet.h"
#include "Graphics/GraphicsBullet.h"

class CreateBullet : public Command
{
public:
    explicit CreateBullet(Physics::physServer* P, Logic::logServer* L, Graphics::graphServer* G) : CommPhysServer(P), CommLogServer(L), CommGraphServer(G) {};
    void Execute() const override;

private:
    Physics::physServer* CommPhysServer{ nullptr };
    Logic::logServer* CommLogServer{ nullptr };
    Graphics::graphServer* CommGraphServer{ nullptr };
};