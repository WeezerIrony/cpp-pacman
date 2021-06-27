#pragma once
#include "../core/server.h"

namespace Physics
{
    class physServer;
    class Entity
    {
    public:
        Entity(physServer& Server);
        ~Entity();
        virtual void onFrame(float dt) = 0;
    private: physServer& m_server;
    };

    class physServer : public Core::Server<Entity>
    {
    public:
        virtual ~physServer() = default;
        virtual void onFrameImpl(float dt) override;
    };
}

