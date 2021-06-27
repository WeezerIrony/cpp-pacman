#pragma once
#include "Splinter.h"
#include "../core/server.h"

namespace Physics
{
    class Bullet : public Entity
    {
    public:
        Bullet(physServer& Server) : Entity(Server)
        {
        }
        ~Bullet();
        virtual void onFrame(float dt) override;
    private:
        std::vector<Splinter> splinters;
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);
        void Explode();
        float bulletX;
        float bulletY;
        float bulletVY;
        bool isExploded;
    };
}

