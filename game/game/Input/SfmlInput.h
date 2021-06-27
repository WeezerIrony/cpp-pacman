#pragma once
#include <iostream>
#include "Input.h"
class SfmlInput:public Input
{
public:
    virtual void OnFrame() override
    { 
        std::cout << "SfmlInput::OnFrame" << std::endl;
    }
    virtual bool isPressed(Button button) override
    {
    }
};