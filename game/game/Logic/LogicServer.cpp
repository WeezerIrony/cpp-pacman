#include "LogicServer.h"

namespace Logic
{
    Entity::Entity(logServer& Server): m_server(Server)
    {
        m_server.registerEntity(this);
    }

    Entity::~Entity()
    {
        m_server.unregisterEntity(this);
    }

    void logServer::onFrameImpl(float dt)
    {
        if (!delete_entities.empty())
        {
            for (auto entity : delete_entities)
            {
                delete entity;
            }
            delete_entities.clear();
        }
    }

    void logServer::RegisterDeleteEntity(Entity* entity)
    {
        delete_entities.push_back(entity);
    }
}

