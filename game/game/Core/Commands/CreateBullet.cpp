#pragma once
#include "CreateBullet.h"

void CreateBullet::Execute() const
{
    auto y = 100;
    auto x = (double)rand() / RAND_MAX * 900;
    auto v = 300;
    Physics::Bullet* PBullet = new Physics::Bullet(*CommPhysServer, x, y, v);
    Graphics::Bullet* GBullet = new Graphics::Bullet(*CommGraphServer);
    auto LBullet = new Logic::Bullet(*CommLogServer, PBullet, GBullet);
}
