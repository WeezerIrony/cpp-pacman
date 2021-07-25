#pragma once

namespace Physics
{
    class Splinter {
    public:
        Splinter(float x, float y, float z, float vX, float vY, float vZ, const Box& wBox) : splinterPosition{ x,y,z }, splinterVelocity{ vX,vY,vZ }, splinterBox(wBox)
        {
        }
        void Simulate(float dt);
        bool SplinterOnGround() const
        { 
            return splinterPosition.y <= splinterBox.y0;
        }
        std::vector<float> GetCoords() const
        {
            return { splinterPosition.x, splinterPosition.y, splinterPosition.z };
        }
    private:
        Core::vector3 splinterPosition;
        Core::vector3 splinterVelocity;
        const Box& splinterBox;
    };
}

