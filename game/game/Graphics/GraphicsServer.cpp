#include "GraphicsServer.h"
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>


namespace Graphics
{
    Entity::Entity(graphServer& Server): m_server(Server)
    {
        m_server.registerEntity(this);
    }

    Entity::~Entity()
    {
        m_server.unregisterEntity(this);
    }

    graphServer::graphServer()
    {
        m_buttons.fill(false);
    }

    graphServer::~graphServer()
    {
        Close();
    }

    void graphServer::Open()
    {
        CreateContext();
        Render(10);
    }

    void graphServer::Close()
    {
        m_window->close();
    }

    bool graphServer::IsPressed(Input::Button b) const
    {
        return m_buttons[unsigned(b)];
    }

    void graphServer::CreateContext()
    {
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Width, Height), "FireWorks",
            sf::Style::Titlebar | sf::Style::Close);

        m_window->setVerticalSyncEnabled(true);
        m_font = std::make_unique<sf::Font>();
        m_font->loadFromFile("../Resources/sansation.ttf");

        m_bulletTexture = std::make_unique<sf::Texture>();
        m_bulletTexture->loadFromFile("../Resources/bullet.png");
    }

    void graphServer::UpdateButtons()
    {
        m_buttons[unsigned(Input::Button::P_C)] = sf::Keyboard::isKeyPressed(sf::Keyboard::C);
    }

    void graphServer::BeforeRender()
    {
        m_window->clear(sf::Color(255, 255, 255));
        m_buttons.fill(false);
    }

    void graphServer::Render(std::size_t activeTime)
    {
        m_window->display();

        sf::Event event{};

        auto&& start = std::chrono::high_resolution_clock::now();
        std::size_t elapsedTime{ 0 };
        while (elapsedTime < activeTime)
        {
            if (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::EventType::KeyPressed)
                    UpdateButtons();
            }

            auto&& end = std::chrono::high_resolution_clock::now();
            elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
    }
}

