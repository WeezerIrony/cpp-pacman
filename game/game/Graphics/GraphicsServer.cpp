#include "GraphicsServer.h"

namespace Graphics
{
    Entity::Entity(graphServer& Server): m_server(Server)
    {
        m_server.registerEntity(this);
    }

    Entity::~Entity()
    {
        m_server.unregisterEntity(this);
    }

    void graphServer::onFrameImpl(float dt)
    {
    }
}

