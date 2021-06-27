#include "Application.h"

Application::Application(Input* input, Audio* audio, Logic* logic, AiModule* ai, Graphics* graphics)
    : m_input(input)
    , m_audio(audio)
    , m_logic(logic)
    , m_ai(ai)
    , m_graphics(graphics)
{
}

bool Application::Activate()
{
    return true;
}

void Application::Run()
{
    //m_input->OnFrame(); // handle user input, related info will be stored in the inner map
    //m_logic->OnFrame(); // update user actions, interactions with vworld
    //m_ai->OnFrame(); // simulate npc, traffic, e.t.c
    //m_logic->OnRender(); // set graphysics properties 
    //m_ai->OnRender(); // set graphysics properties 
    //m_graphics->Render();
    //m_audio->OnFrame(); // evidently
}

void Application::Deactivate()
{
}