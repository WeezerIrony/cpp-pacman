#pragma once

class Audio;
class Logic;
class Input;
class AiModule;
class Graphics;

class Application final
{
public:
    bool Activate()
    {
    }
    void Run()
    {
        m_input->OnFrame(); // handle user input, related info will be stored in the inner map
        m_logic->OnFrame(); // update user actions, interactions with vworld
        m_ai->OnFrame(); // simulate npc, traffic, e.t.c
        m_logic->OnRender(); // set graphysics properties 
        m_ai->OnRender(); // set graphysics properties 
        m_graphics->Render();
        m_audio->OnFrame(); // evidently
    }
    void Deactivate()
    {
    }

private:
    Application(Input* input, Audio* audio, Logic* logic; AiModule* ai, Graphics* graphics)
        : m_input(input)
        , m_audio(audio)
        , m_logic(logic)
        , m_ai(ai)
        , m_graphics(graphics)
    {
    }

    Input* m_input;
    Audio* m_audio;
    Logic* m_logic;
    AiModule* m_ai;
    Graphics* m_graphics;

friend class ApplicationBuilder;

};