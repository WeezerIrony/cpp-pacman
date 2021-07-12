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
        PhysServer->onFrame(FrameTimeSec);
        LogServer->onFrame(FrameTimeSec);

        GraphServer->BeforeRender();

        GraphServer->onFrame(FrameTimeSec);


        auto&& end = std::chrono::high_resolution_clock::now();
        auto&& deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (FrameTime > deltaTime)
        {
            GraphServer->Render(FrameTime - deltaTime);
        }
    }

    GraphServer->Close();
}

void Application::Deactivate()
{
}

void Application::HandleEvents() const
{
    if (GraphServer->IsPressed(Input::Button::P_C))
    {
        auto y = 100;
        auto x = (double)rand() / RAND_MAX * 900;
        auto v = 300;
        Physics::Bullet* PBullet = new Physics::Bullet(*PhysServer, x, y, v);
        Graphics::Bullet* GBullet = new Graphics::Bullet(*GraphServer);
        auto LBullet = new Logic::Bullet(*LogServer, PBullet, GBullet);
    }
}
