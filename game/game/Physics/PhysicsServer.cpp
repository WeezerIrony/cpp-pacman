#include "PhysicsServer.h"

namespace Physics
{
    void physServer::onFrameImpl(float dt)
    {
    }

    const Box& physServer::getWorldBox() const
    {
        return WorldBox;
    }
}

