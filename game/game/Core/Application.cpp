#include "Application.h"
#include "Commands/CreateBullet.h"
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
        InpServer->OnBeforeFrame();

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
    if (InpServer->IsPressed(Input::Button::P_C))
    {
        CreateBullet creation(PhysServer, LogServer, GraphServer, InpServer);
        creation.Execute();
    }
}
