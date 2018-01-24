#include <iostream>
#include "player.h"

Player::Player() : Entity()
{
	this->addSprite("assets/car.tga");
	this->sprite()->color = RED;

	slowDownCheck = true;
	stopMovement = false;

	velocity = Vector2(0, 0, -HALF_PI);
	polar = Polar(-90 * DEG_TO_RAD, 400.0f);
}


Player::~Player()
{
	
}

void Player::update(float deltaTime)
{

	if (stopMovement == false) {
		float rotspeed = 3.14f;

		

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
	else {
		velocity -= velocity / 50.0f;
	}
}

void Player::Reset() {
	this->rotation.z = HALF_PI;
	polar = Polar(-90 * DEG_TO_RAD, 400.0f);
	this->velocity = Vector2(0, 0);
}
