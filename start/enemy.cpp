#include <iostream>
#include "enemy.h"

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/enemy_car.tga");
	this->sprite()->color = RED;

	t.start();

	voidChecker = true;

	stopEnemyMovement = false;

	time = int(0);

	stopTime = true;
}


Enemy::~Enemy()
{
	t.stop();
}

void Enemy::update(float deltaTime)
{
	if (stopEnemyMovement == false) {
		this->rotation.z = velocity.getAngle();
		this->position += velocity;
		acceleration = Vector2(0, 0);
	}

	if (stopTime == false) {
		time++;
	}

	if (time >= 300 && time <= 400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-400, -900));
		}
	}
	else if (time >= 1350 && time <= 1400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(50, -900));
		}
	}
	else if (time >= 1800 && time <= 1900) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, -900));
		}
	}
	else if (time >= 2050 && time <= 2150) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -300));
		}
	}
	else if (time >= 2700 && time <= 2800) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -1));
		}
	}
	else if (time >= 3100 && time <= 3200) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 200));
		}
	}
	else if (time >= 3500 && time <= 3600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, -150));
		}
	}
	else if (time >= 4150 && time <= 4200) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, 100));
		}
	}
	else if (time >= 4570 && time <= 4600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(700, 800));
		}
	}
	else if (time >= 4700 && time <= 4750) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, 300));
		}
	}
	else if (time >= 4850 && time <= 4900) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, 100));
		}
	}
	else if (time >= 5300 && time <= 5400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-10, 300));
		}
	}
	else if (time >= 5900 && time <= 6050) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(200, 900));
		}
	}
	else if (time >= 6300 && time <= 6400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(400, 400));
		}
	}
	else if (time >= 6500 && time <= 6600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 400));
		}
	}
	else if (time >= 6650 && time <= 6700) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(900, 100));
		}
	}
	else if (time >= 7200 && time <= 7300) {
		if (voidChecker == true){
			voidChecker = false;
			direction(Point2(200, 400));
		}
	}
	else if (time >= 7350 && time <= 7400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-300, 900));
		}
	}
	else if (time >= 7600 && time <= 7700) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 900));
		}
	}
	else if (time >= 7850 && time <= 7950) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-700, 400));
		}
	}
	else if (time >= 8400 && time <= 8500) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-400, 400));
		}
	}
	else if (time >= 9300 && time <= 9400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 400));
		}
	}
	else if (time >= 9500 && time <= 9600) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, 100));
		}
	}
	else if (time >= 10200 && time <= 10300) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, -100));
		}
	}
	else if (time >= 10350 && time <= 10400) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-900, -400));
		}
	}
	else if (time >= 10600 && time <= 10700) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-999, -999));
		}
	}
	else if (time >= 10900 && time <= 11000) {
		if (voidChecker == true) {
			voidChecker = false;
			direction(Point2(-100, -600));
		}
	}
	else if (time >= 11200 && time <= 11300) {
		if (voidChecker == true) {
			voidChecker = false;
			backToHome();
		}
	}
	else if (time >= 11780 && time <= 11780) {
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
	if (stopEnemyMovement == false) {
		Vcheckpoint = Vector2(checkpoint.x, checkpoint.y);
		location = Vector2(0, 0);
		dir = Vector2() - Vector2(Vcheckpoint, location);
		velocity = Vector2(0, 0);
		acceleration = Vector2(0, 0);

		Vcheckpoint = Vector2(checkpoint.x, checkpoint.y);
		location = Vector2(0, 0);
		dir = Vector2() - Vector2(Vcheckpoint, location);

		dir * 0.5f;
		dir.normalize();
		dir *= 40;
		acceleration = dir;
		velocity += acceleration;
		velocity.limit(0.8f);
		this->rotation.z = velocity.getAngle();
		acceleration = Vector2(0, 0);
	}
}

void Enemy::backToHome() {
	if (stopEnemyMovement == false) {
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
}


