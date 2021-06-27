#pragma once
#include "../core/server.h"


namespace Logic
{
    class logServer;
    class Entity
    {
    public:
        Entity(logServer& Server);
        ~Entity();
        virtual void onFrame(float dt) = 0;
    private: logServer& m_server;
    };

    class logServer : public Core::Server<Entity>
    {
    public:
        virtual ~logServer() = default;
        virtual void onFrameImpl(float dt) override;
    };

}