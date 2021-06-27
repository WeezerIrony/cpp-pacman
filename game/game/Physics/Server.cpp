#include "server.h"

namespace Physics
{
    Entity::Entity(physServer& Server): m_server(Server)
    {
        m_server.registerEntity(this);
    }

    Entity::~Entity()
    {
        m_server.unregisterEntity(this);
    }

    void physServer::onFrameImpl(float dt)
    {
    }
}

