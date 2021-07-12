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

    graphServer::graphServer(Input::IServer* input)
    {
        m_input = input;
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

    void graphServer::CreateContext()
    {
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Width, Height), "game",
            sf::Style::Titlebar | sf::Style::Close);

        m_window->setVerticalSyncEnabled(true);
        m_font = std::make_unique<sf::Font>();
        m_font->loadFromFile("../Resources/sansation.ttf");

        m_bulletTexture = std::make_unique<sf::Texture>();
        m_bulletTexture->loadFromFile("../Resources/bullet.png");
    }


    void graphServer::BeforeRender()
    {
        m_window->clear(sf::Color(255, 255, 255));
    }

    void graphServer::Render(std::size_t activeTime)
    {
        m_window->display();

        auto&& start = std::chrono::high_resolution_clock::now();
        std::size_t elapsedTime{ 0 };
        while (elapsedTime < activeTime)
        {
            sf::Event event{};
            if (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::EventType::KeyPressed)
                {
                    m_input->UpdateButtons();
                }
            }

            auto&& end = std::chrono::high_resolution_clock::now();
            elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
    }
}

