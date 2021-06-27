#pragma once
#include <iostream>
#include "Logic.h"

class GameLogic:public Logic 
{
public:
    virtual void OnFrame() override
    { 
        std::cout << "GameLogic::OnFrame" << std::endl; 
    }
    virtual void OnRender() override
    {
    }
};