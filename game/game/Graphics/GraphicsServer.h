#pragma once
#include "../core/mainserver.h"
#include "GraphicsEntity.h"
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
        sf::Texture& WallTexture() const { return *m_wallTexture; }
        sf::Texture& OrbTexture() const { return *m_orbTexture; }
        sf::Texture& AlphaTexture() const { return *m_alphaTexture; }
        sf::Texture& BulletTexture() const { return *m_bulletTexture; }

        std::size_t GetHeight() const { return Height; }
    private:
        void CreateContext();

        Input::IServer* m_input;
        std::unique_ptr<sf::RenderWindow> m_window;
        std::unique_ptr<sf::Font> m_font;
        std::unique_ptr<sf::Texture> m_bulletTexture;
        std::unique_ptr<sf::Texture> m_wallTexture;
        std::unique_ptr<sf::Texture> m_orbTexture;
        std::unique_ptr<sf::Texture> m_alphaTexture;

        std::size_t m_particles;

        static constexpr std::size_t Height{ 900 };
        static constexpr std::size_t Width{ 900 };
    };
}

