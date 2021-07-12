#pragma once
#include "../core/mainserver.h"


namespace Input
{
    enum class Button {
        P_C = 0,
        Count,
    };

    class IServer
    {
    public:
        IServer() = default;
        virtual ~IServer() = default;
        virtual bool IsPressed(Button b) const = 0;
        virtual void UpdateButtons() = 0;
        virtual void OnBeforeFrame() = 0;
    };
}
