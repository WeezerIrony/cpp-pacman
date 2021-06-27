#pragma once


class Audio 
{
public:
    virtual ~Audio() = default;
    virtual void OnFrame() = 0;
};