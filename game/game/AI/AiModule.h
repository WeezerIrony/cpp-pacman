#pragma once
class AiModule {
public:
    virtual ~AiModule() = default;
    virtual void OnFrame() = 0;
    virtual void OnRender() = 0;
};