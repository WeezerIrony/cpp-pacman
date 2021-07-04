#pragma once
enum class Button {
    P_C = 0,
    Count,
};

class IServer 
{
public:
    IServer() = default;
    virtual ~IServer() = default;
    virtual void OnFrame() = 0;
    virtual bool isPressed(Button button) = 0;
};