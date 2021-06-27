#include "ApplicationBuilder.h"

ApplicationBuilder ApplicationBuilder::Create()
{
    return ApplicationBuilder();
}

Application ApplicationBuilder::Get()
{

}

ApplicationBuilder& ApplicationBuilder::AddInput(Input* input)
{
    in = input;
}

ApplicationBuilder& ApplicationBuilder::AddAi(AiModule* ai)
{
    // TODO: insert return statement here
}

ApplicationBuilder& ApplicationBuilder::AddGraphics(Graphics* graphics)
{
    // TODO: insert return statement here
}

ApplicationBuilder& ApplicationBuilder::AddLogic(Logic* logic)
{
    // TODO: insert return statement here
}

ApplicationBuilder::ApplicationBuilder()
{

}