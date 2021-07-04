#include "GraphicsBullet.h"
#include "GraphicsServer.h"
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <cassert>

namespace Graphics
{
	Bullet::Bullet(graphServer& Server) : Entity(Server), m_texture(Server.BulletTexture())
	{
		m_shape = std::make_unique<sf::Sprite>();

		m_shape->setTexture(m_texture, true);
		m_shape->setPosition(rX, rY);
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::onFrame(float dt)
	{
		if (isRocket)
		{
			m_shape->setPosition(rX, m_server.GetHeight() - rY);
			m_server.RenderWindow().draw(*m_shape);
		}
		else
		{
			sf::CircleShape circle;
			circle.setRadius(5);
			circle.setOutlineColor(sf::Color::Red);
			circle.setOutlineThickness(1);

			for (auto&& splinter : splinters)
			{
				circle.setPosition(splinter.x, m_server.GetHeight() - splinter.y);
				m_server.RenderWindow().draw(circle);
			}
		}
	}
	
	void Bullet::setSplinterPosition(int index, float x, float y)
	{
		if (splinters.size() > index)
		{
			splinters[index].x = x;
			splinters[index].y = y;
		}
		else
		{
			assert(index == splinters.size());
			splinters.emplace_back(x, y);
		}
	}
	void Bullet::setRocketPosition(float x, float y)
	{
		rX = x;
		rY = y;
	}
}