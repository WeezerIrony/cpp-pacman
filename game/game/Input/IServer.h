#pragma once

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
    };
}
