#pragma once
#include "../core/mainserver.h"
#include "Input/IServer.h"
#include <memory>
#include <array>

namespace sf
{
    class RenderWindow;
    class Text;
    class Font;
    class Texture;
}

namespace Graphics
{
    class graphServer;
    class Entity
    {
    public:
        Entity(graphServer& Server);
        virtual ~Entity();
        virtual void OnFrame(float dt) = 0;
    protected: 
        graphServer& m_server;
    };

    class graphServer final : public Core::Server<Entity>
    {
    public:
        graphServer(Input::IServer* input);
        virtual ~graphServer();

        void BeforeRender();
        void Render(std::size_t activeTime);
        void Open();
        void Close();

        sf::RenderWindow& RenderWindow() const { return *m_window; }
        sf::Texture& BulletTexture() const { return *m_bulletTexture; }

        std::size_t GetHeight() const { return Height; }
    private:
        void CreateContext();

        Input::IServer* m_input;
        std::unique_ptr<sf::RenderWindow> m_window;
        std::unique_ptr<sf::Font> m_font;
        std::unique_ptr<sf::Texture> m_bulletTexture;

        std::size_t m_particles;

        static constexpr std::size_t Height{ 900 };
        static constexpr std::size_t Width{ 900 };
    };
}

