#include <iostream>
#include "player.h"

Player::Player() : Entity()
{
	this->addSprite("assets/car.tga");
	this->sprite()->color = RED;

	slowDownCheck = true;
}


Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (velocityCheck == false) {
		
		velocity.limit(500);
	}
	if (velocityCheck == true) {

		if (velocity > Vector2(100, 100)) {
			
			velocity -= velocity / 50.0f;
			slowDownCheck = false;
		}
		else {
			slowDownCheck = true;
			velocity.limit(100);
		}
		
	}

	if (input()->getKey(KeyCode::W)) {
		if (slowDownCheck == true) {
			velocity += polar.cartesian() * deltaTime; // thrust
		}
	}
	else {
		velocity -= velocity / 75.0f;
	}
	if (input()->getKey(KeyCode::D)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::S)) {
		velocity -= polar.cartesian() * deltaTime; // brake
	}
	if (input()->getKey(KeyCode::A)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
}
