#pragma once

namespace Logic
{
    class logServer;
    class Entity
    {
    public:
        Entity(logServer& Server);
        virtual ~Entity();
        virtual void OnFrame(float dt) = 0;
    protected:
        logServer& m_server;
    };
}


