#pragma once
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
            if it != entities.end() 
            {
                entities.erase(it);
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

