#pragma once
#include "../core/mainserver.h"


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