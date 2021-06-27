#pragma once

class Audio;
class Logic;
class Input;
class AiModule;
class Graphics;

class Application final
{
public:
    bool Activate();
    void Run();
    void Deactivate();

private:
    Application(Input* input, Audio* audio, Logic* logic, AiModule* ai, Graphics* graphics);
    Input* m_input;
    Audio* m_audio;
    Logic* m_logic;
    AiModule* m_ai;
    Graphics* m_graphics;

friend class ApplicationBuilder;
};