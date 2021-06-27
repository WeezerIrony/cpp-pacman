#pragma once
#include "../core/server.h"


namespace Graphics
{
    class graphServer;
    class Entity
    {
    public:
        Entity(graphServer& Server);
        ~Entity();
        virtual void onFrame(float dt) = 0;
    private: graphServer& m_server;
    };

    class graphServer : public Core::Server<Entity>
    {
    public:
        virtual ~graphServer() = default;
        virtual void onFrameImpl(float dt) override;
    };

}

