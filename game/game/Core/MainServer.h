#pragma once
#include "Math.h"
#include <vector>
#include<algorithm>


namespace Core
{
    template <typename Entity>
    class Server
    {
    public:
        void onFrame(float dt)
        {
            for (auto* e : entities)
            {
                e->OnFrame(dt);
            }
            onFrameImpl(dt);
        }
        void registerEntity(Entity* entity)
        {
            entities.push_back(entity);
        }
        void unregisterEntity(Entity* entity)
        {
            auto&& it = std::find(entities.begin(), entities.end(), entity);
            if (it != entities.end() )
            {
                entities.erase(it);
            }
        }
        template <typename RequestedEntity>
        RequestedEntity* getEntity()
        {
            for (auto* e : entities)
            {
                if (auto* f = dynamic_cast<RequestedEntity*>(e))
                    return e;
            }
        }
        virtual ~Server() = default;
    protected:
        virtual void onFrameImpl(float dt)
        {
        }
        std::vector<Entity*> entities;
    };
}

