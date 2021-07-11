#include "ApplicationBuilder.h"

ApplicationBuilder ApplicationBuilder::Create()
{
    return ApplicationBuilder();
}

//Application ApplicationBuilder::Get()
//{
//    return Application(in, aud, lg, am, gfx);
//}
//
//ApplicationBuilder& ApplicationBuilder::AddInput(Input* input)
//{
//    in = input;
//    return *this;
//}
//
//ApplicationBuilder& ApplicationBuilder::AddAi(AiModule* ai)
//{
//    am = ai;
//    return *this;
//}
//
//ApplicationBuilder& ApplicationBuilder::AddGraphics(Graphics* graphics)
//{
//    gfx = graphics;
//    return *this;
//}
//
//ApplicationBuilder& ApplicationBuilder::AddLogic(Logic* logic)
//{
//    lg = logic;
//    return *this;
//}
//
//ApplicationBuilder::ApplicationBuilder()
//{
//}