#include <iostream>
#include "coin.h"

Coin::Coin() : Entity()
{
	this->addSprite("assets/coin.tga");
}


Coin::~Coin()
{
}

void Coin::update(float deltaTime)
{
	if (colCheck == true) {
		time++;

		if (time <= 100) {
			this->scale -= Point(0.01f, 0.01f);
		}
		else {
			
			deleteCoin = true;
		}
	}
}

void Coin::CoinScore() {

}
