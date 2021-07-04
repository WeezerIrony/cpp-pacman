#pragma once

namespace Physics
{
    class Splinter {
    public:
        Splinter(float x, float y, float vX, float vY) : splinterX(x), splinterY(y), splinterVX(vX), splinterVY(vY)
        {
        }
        void Simulate(float dt);
        bool SplinterOnGround() const
        { 
            return splinterY <= 0;
        }
        std::pair<float, float> GetCoords() const
        {
            return { splinterX, splinterY };
        }
    private:
        float splinterX;
        float splinterY;
        float splinterVX;
        float splinterVY;
    };
}

