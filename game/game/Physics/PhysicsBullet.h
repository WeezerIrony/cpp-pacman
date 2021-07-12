#pragma once
#include "PhysicsServer.h"
#include <utility>
#include "Splinter.h"

namespace Physics
{
    class Bullet : public Entity
    {
    public:
        Bullet(physServer& Server, float bX, float bY, float bVY) : Entity(Server), bulletX(bX), bulletY(bY), bulletVY(bVY)
        {
        }
        ~Bullet();
        virtual void OnFrame(float dt) override;
        bool IsOnGround() const
        {
            return SplintersOnGround;
        }
        bool GetExplode() const
        {
            return isExploded;
        }
        std::pair<float, float> GetCoords() 
        {
            return { bulletX, bulletY };
        }
        const std::vector<Splinter>& GetSplinters() const 
        {
            return splinters;
        }
    private:
        std::vector<Splinter> splinters;
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);
        bool SplintersOnGround{ false };
        void Explode();
        float bulletX{ 0 };
        float bulletY{ 0 };
        float bulletVY{ 0 };
        bool isExploded{ false };
    };
}

