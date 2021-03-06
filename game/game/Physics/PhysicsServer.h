#pragma once
#include "PhysicsEntity.h"
#include "../core/mainserver.h"

struct Box {
    float x0{ 0.f };
    float y0{ 0.f };

    float xs{ 0.f };
    float ys{ 0.f };
};


namespace Physics
{
    class physServer : public Core::Server<Entity>
    {
    public:
        virtual ~physServer() = default;
        virtual void onFrameImpl(float dt) override;
        const Box& getWorldBox() const;
    private:
        constexpr static Box WorldBox{ 0,100,900,900 };
    };
}

