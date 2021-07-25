#pragma once
#include "PhysicsServer.h"
#include <utility>
#include "Splinter.h"

namespace Physics
{
    class Bullet : public Entity
    {
    public:
        Bullet(physServer& Server, float bX, float bY, float bVY) : Entity(Server), bulletPosition{ bX, bY }, bulletVY(bVY)
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
        Core::vector3& GetCoords() 
        {
            return bulletPosition;
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
        Core::vector3 bulletPosition;
        float bulletVY{ 0 };
        bool isExploded{ false };
    };
}

