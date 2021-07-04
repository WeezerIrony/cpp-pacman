#pragma once
#include "GraphicsServer.h"

namespace Graphics
{
	class Bullet : public Entity 
	{
	public:
		Bullet(graphServer& Server);
		~Bullet();
		virtual void onFrame(float dt) override;
		void setRenderType(bool renderType)
		{
			isRocket = renderType;
		}
		void setSplinterPosition(int index, float x, float y);
		void setRocketPosition(float x, float y);

	private:
		bool isRocket{true};
		struct Position final
		{
			Position(float newX, float newY) : x(newX), y(newY) {}
			float x{ 0 };
			float y{ 0 };
		};
		float rX{ 0 };
		float rY{ 0 };
		std::vector<Position> splinters;
	};
}
