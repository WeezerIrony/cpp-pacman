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
        ~Entity();
        virtual void onFrame(float dt) = 0;
    protected: 
        graphServer& m_server;
    };

    class graphServer final : public Core::Server<Entity>, public Input::IServer
    {
    public:
        graphServer();
        virtual ~graphServer() = default;

        void BeforeRender();
        void Render(std::size_t activeTime);
        void Open();
        void Close();

        bool IsPressed(Input::Button b) const;

        sf::RenderWindow& RenderWindow() const { return *m_window; }
        sf::Texture& BulletTexture() const { return *m_bulletTexture; }

        std::size_t GetHeight() const { return Height; }
    private:
        void CreateContext();
        void UpdateButtons();

        std::unique_ptr<sf::RenderWindow> m_window;
        std::unique_ptr<sf::Font> m_font;
        std::unique_ptr<sf::Texture> m_bulletTexture;

        std::size_t m_particles;
        std::array<bool, unsigned(Input::Button::Count)> m_buttons;

        static constexpr std::size_t Height{ 900 };
        static constexpr std::size_t Width{ 900 };
    };
}

