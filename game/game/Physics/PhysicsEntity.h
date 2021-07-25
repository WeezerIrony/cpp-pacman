#pragma once

namespace Physics
{
    class physServer;
    class Entity
    {
    public:
        Entity(physServer& Server);
        virtual ~Entity();
        virtual void OnFrame(float dt) = 0;
    protected: physServer& m_server;
    };
}


