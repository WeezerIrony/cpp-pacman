#pragma once
#include "LogicServer.h"

namespace Physics
{
    class Bullet;
}

namespace Graphics
{
    class Bullet;
}


namespace Logic
{
    class Bullet : public Entity
    {
    public:
        Bullet(logServer& Server, Physics::Bullet* pb, Graphics::Bullet* gb); 
        ~Bullet();
        void updateGraphics();
        virtual void onFrame(float dt) override;
    private:
        Physics::Bullet* pbullet;
        Graphics::Bullet* gbullet;
    };
}
