#include <iostream>
#include "enemy.h"

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/enemy_car.tga");
	this->sprite()->color = RED;

	voidChecker = true;

	time = int(0);

	direction(Point2(0, -100));

	//velocity = Vector2(0, 0);
	//acceleration = Vector2(0.03, 0.03);
	//maxSteeringForce = 0.02;
	//topSpeed = 1;
}


Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	
	//velocity = Vector2(0, 0);
	//acceleration = Vector2(0, 0);
	//Vcheckpoint = Vector2(checkpoint.x, checkpoint.y);
	//location = Vector2(0, 0);
	//dir = Vector2() - Vector2(Vcheckpoint, location);
	//Vector2 desiredVelocity = dir - location;
	//desiredVelocity.getNormalized();
	//steering = desiredVelocity - velocity;
	//steering.limit(maxSteeringForce);
	//addForce(steering);
	//velocity += acceleration;
	//velocity.normalize();
	//velocity.limit(topSpeed);

	//static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	//dir * 0.5f;
	//dir.normalize();
	//dir *= 40;
	//acceleration = dir;
	//velocity += acceleration;
	//velocity.limit(1);
	this->rotation.z = velocity.getAngle();
	this->position += velocity;
	acceleration = Vector2(0, 0);

	time++;

	if (time >= 200 && time <= 300) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-400, -900));
		}
	}
	else if (time >= 950 && time <= 1000) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(50, -900));
		}
	}
	else if (time >= 1500 && time <= 1600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, -900));
		}
	}
	else if (time >= 1650 && time <= 1750) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -300));
		}
	}
	else if (time >= 2100 && time <= 2200) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -1));
		}
	}
	else if (time >= 2600 && time <= 2700) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 200));
		}
	}
	else if (time >= 2900 && time <= 3000) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -150));
		}
	}
	else if (time >= 3450 && time <= 3500) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, 100));
		}
	}
	else if (time >= 3600 && time <= 3700) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, 800));
		}
	}
	else if (time >= 3800 && time <= 3850) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, 300));
		}
	}
	else if (time >= 3900 && time <= 4000) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, 100));
		}
	}
	else if (time >= 4250 && time <= 4350) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, 300));
		}
	}
	else if (time >= 4500 && time <= 4600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(200, 900));
		}
	}
	else if (time >= 5050 && time <= 5100) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(400, 400));
		}
	}
	else if (time >= 5250 && time <= 5300) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 400));
		}
	}
	else if (time >= 5350 && time <= 5400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 100));
		}
	}
	else if (time >= 5800 && time <= 5850) {
		if (voidChecker == true){
			voidChecker = false;
			direction(Point2(200, 400));
		}
	}
	else if (time >= 5900 && time <= 5950) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-300, 900));
		}
	}
	else if (time >= 6100 && time <= 6200) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 900));
		}
	}
	else if (time >= 6350 && time <= 6400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-700, 400));
		}
	}
	else if (time >= 6800 && time <= 6900) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-400, 400));
		}
	}
	else if (time >= 7400 && time <= 7500) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 400));
		}
	}
	else if (time >= 7800 && time <= 7900) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 100));
		}
	}
	else if (time >= 8000 && time <= 8100) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, -100));
		}
	}
	else if (time >= 8400 && time <= 8500) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, -400));
		}
	}
	else if (time >= 8600 && time <= 8650) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-999, -999));
		}
	}
	else if (time >= 8700 && time <= 8800) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, -600));
		}
	}
	else if (time >= 9300 && time <= 9400) {
		if (voidChecker == true) {
			voidChecker = false;
			backToHome();
		}
	}
	else if (time >= 9600 && time <= 9600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(0, -100));
			time = 0;
		}
	}
	else {
		voidChecker = true;
	}
}

void Enemy::addForce(Vector3 force) {
	this->acceleration += force;
}

void Enemy::direction(Point2 checkpoint) {

	Vcheckpoint = Vector2(checkpoint.x, checkpoint.y);
	location = Vector2(0, 0);
	dir = Vector2() - Vector2(Vcheckpoint, location);
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	
	//maxSteeringForce = 0.3;
	//topSpeed = 1;
	Vcheckpoint = Vector2(checkpoint.x, checkpoint.y);
	location = Vector2(0, 0);
	dir = Vector2() - Vector2(Vcheckpoint, location);
	//Vector2 desiredVelocity = dir - location;
	//desiredVelocity.getNormalized();
	//steering = desiredVelocity - velocity;
	//steering.limit(maxSteeringForce);
	//addForce(steering);
	//velocity += acceleration;
	//velocity.normalize();
	//velocity.limit(topSpeed);
	
	//static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	dir * 0.5f;
	dir.normalize();
	dir *= 40;
	acceleration = dir;
	velocity += acceleration;
	velocity.limit(1);
	this->rotation.z = velocity.getAngle();
	//this->position += velocity;
	acceleration = Vector2(0, 0);
}

void Enemy::backToHome() {

	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	Vcheckpoint = Vector2(-1000, 300);
	location = Vector2(this->position);
	dir = Vector2() - Vector2(Vcheckpoint, location);

	dir * 0.5f;
	dir.normalize();
	dir *= 40;
	acceleration = dir;
	velocity += acceleration;
	velocity.limit(1);
}


