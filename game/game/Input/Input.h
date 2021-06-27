#pragma once
enum class Button {
    
};
class Input {
public:
    virtual ~Input() = default;
    virtual void OnFrame() = 0;
    virtual bool isPressed(Button button) = 0;
};