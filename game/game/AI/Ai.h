#pragma once
#include<iostream>
#include "AiModule.h"
class Ai:public AiModule {
public:
    virtual void OnFrame() override { std::cout << "Ai::OnFrame" << std::endl; }
    virtual void OnRender() override {}
};