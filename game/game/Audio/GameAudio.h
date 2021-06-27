#pragma once
#include<iostream>
#include "Audio.h"
class GameAudio:public Audio 
{
public:
    virtual void OnFrame() override
    {
        std::cout << "GameAudio::OnFrame" << std::endl;
    }
};