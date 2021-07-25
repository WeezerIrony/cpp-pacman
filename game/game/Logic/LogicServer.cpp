#include "LogicServer.h"

namespace Logic
{
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

