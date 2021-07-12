#include "Application.h"
#include "Physics/PhysicsBullet.h"
#include "Logic/LogicBullet.h"
#include "Graphics/GraphicsBullet.h"
#include <chrono>

namespace
{
    constexpr std::size_t FrameTime{ 16 }; // msec
}

Application::~Application()
{

}

bool Application::Activate()
{
    GraphServer->Open();
    return true;
}

void Application::Run() const
{
    for (;;)
    {
        auto&& start = std::chrono::high_resolution_clock::now();

        HandleEvents();
        constexpr float FrameTimeSec{ float(FrameTime) / 1000 };
        PhysServer->onFrameImpl(FrameTimeSec);
        LogServer->onFrameImpl(FrameTimeSec);

        GraphServer->BeforeRender();

        GraphServer->onFrame(FrameTimeSec);

        auto&& end = std::chrono::high_resolution_clock::now();
        auto&& deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        GraphServer->Render(FrameTime - deltaTime);
    }

    GraphServer->Close();
}

void Application::Deactivate()
{
}

void Application::HandleEvents() const
{
    auto y = 100;
    auto x = (double)rand() / RAND_MAX * 900;
    auto v = 300;
    Physics::Bullet* PBullet = new Physics::Bullet(*PhysServer, x, y, v);
    Graphics::Bullet* GBullet = new Graphics::Bullet(*GraphServer);
    auto LBullet = Logic::Bullet(*LogServer, PBullet, GBullet);
}
