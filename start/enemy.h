/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file enemy.h
 *
 * @brief description of Enemy behavior.
 */

#ifndef MYENEMY_H
#define MYENEMY_H

#include <rt2d/entity.h>
#include <rt2d/line.h>

 /// @brief The Enemy class is the Enemy implementation.
class Enemy : public Entity {
public:
	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void direction(Point2 checkpoint);
	void backToHome();
	void addForce(Vector3 force);

private:
	/* add your private declarations */

	Vector2 velocity;
	Vector2 Vcheckpoint;
	Vector2 dir;
	Vector2 acceleration;
	Vector2 location;
	Vector2 desiredVelocity;
	Vector2 steering;

	float maxSteeringForce;
	float topSpeed;

	bool voidChecker;

	int time;
};

#endif /* MYENEMY_H */
