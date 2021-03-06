/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file Player.h
 *
 * @brief description of Player behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

 /// @brief The Player class is the Player implementation.
class Player : public Entity {
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool velocityCheck;
	bool stopMovement;

	void Reset();

private:

	Vector2 velocity;
	Polar polar;

	bool slowDownCheck;
};

#endif /* PLAYER_H */
