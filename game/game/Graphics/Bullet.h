#pragma once
#include "Server.h"

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

	private:
		bool isRocket;
		struct Position final
		{
			Position(float newX, float newY) : x(newX), y(newY) {}
			float x;
			float y;
		};
		std::vector<Position> splinters;
	};
}
