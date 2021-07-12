#include "InputServer.h"
#include <SFML/Graphics.hpp>


namespace Input
{
    bool inServer::IsPressed(Input::Button b) const
    {
        return m_buttons[unsigned(b)];
    }

    void inServer::UpdateButtons()
    {
        m_buttons[unsigned(Input::Button::P_C)] = sf::Keyboard::isKeyPressed(sf::Keyboard::C);
    }

    void inServer::OnBeforeFrame()
    {
        m_buttons.fill(false);
    }
}

