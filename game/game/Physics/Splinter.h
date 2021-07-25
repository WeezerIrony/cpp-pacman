#pragma once

namespace Physics
{
    class Splinter {
    public:
        Splinter(const Core::vector3& position, const Core::vector3& velocity, const Box& wBox) : splinterPosition(position), splinterVelocity(velocity), splinterBox(wBox)
        {
        }
        void Simulate(float dt);
        void InAir(float dt);
        void OnGround();
        bool SplinterOnGround() const
        { 
            return splinterPosition.y <= splinterBox.y0;
        }
        Core::vector3 GetCoords() const
        {
            return splinterPosition;
        }
    private:
        Core::vector3 splinterPosition;
        Core::vector3 splinterVelocity;
        const Box& splinterBox;
    };
}

