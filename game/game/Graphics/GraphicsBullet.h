#pragma once
#include "GraphicsServer.h"
#include <memory>
#include <vector>

namespace sf
{
	class Texture;
	class Sprite;
}

namespace Graphics
{
	class Bullet final : public Entity
	{
	public:
		Bullet(graphServer& Server);
		~Bullet();
		virtual void OnFrame(float dt) override;
		void setRenderType(bool renderType)
		{
			isRocket = renderType;
		}
		void setSplinterPosition(int index, float x, float y);
		void setRocketPosition(float x, float y);

	private:
		sf::Texture& m_texture;
		std::unique_ptr<sf::Sprite> m_shape;
		bool isRocket{false};
		struct Position final
		{
			Position(float newX, float newY) : x(newX), y(newY) {}
			float x;
			float y;
		};
		float rX{ 0 };
		float rY{ 0 };
		std::vector<Position> splinters;
	};
}
