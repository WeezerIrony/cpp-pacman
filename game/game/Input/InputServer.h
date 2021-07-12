#pragma once
#include <array>
#include "../core/mainserver.h"
#include "IServer.h"


namespace Input
{
    class inServer: public IServer
    {
    public:
        inServer() = default;
        virtual ~inServer() = default;
        virtual bool IsPressed(Button b) const override;
        virtual void UpdateButtons() override;
        virtual void OnBeforeFrame() override;
    private:
        std::array<bool, unsigned(Input::Button::Count)> m_buttons;
    };
}
