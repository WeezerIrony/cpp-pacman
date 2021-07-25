#pragma once

namespace Graphics
{
    class graphServer;
    class Entity
    {
    public:
        Entity(graphServer& Server);
        virtual ~Entity();
        virtual void OnFrame(float dt) = 0;
    protected:
        graphServer& m_server;
    };
}


