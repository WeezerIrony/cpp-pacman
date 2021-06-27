#pragma once

#include "Application.h"

class ApplicationBuilder
{
public:
    static ApplicationBuilder Create();
    Application Get();
    ApplicationBuilder& AddInput(Input* input);
    ApplicationBuilder& AddAi(AiModule* ai);
    ApplicationBuilder& AddGraphics(Graphics* graphics);
    ApplicationBuilder& AddLogic(Logic* logics);
private:
    ApplicationBuilder();
    Input* in;
    Audio* aud;
    Logic* lg;
    AiModule* am;
    Graphics* gfx;
};

