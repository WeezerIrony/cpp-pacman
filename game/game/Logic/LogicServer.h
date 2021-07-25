#pragma once
#include "../core/mainserver.h"
#include "LogicEntity.h"

namespace Logic
{
    class logServer : public Core::Server<Entity>
    {
    public:
        virtual ~logServer() = default;
        virtual void onFrameImpl(float dt) override;
        void RegisterDeleteEntity(Entity* entity);
    private:
        std::vector<Entity*> delete_entities;
    };
}