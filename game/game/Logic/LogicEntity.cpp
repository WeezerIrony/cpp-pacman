#pragma once
#include "LogicServer.h"

namespace Logic
{
    Entity::Entity(logServer& Server) : m_server(Server)
    {
        m_server.registerEntity(this);
    }

    Entity::~Entity()
    {
        m_server.unregisterEntity(this);
    }
}