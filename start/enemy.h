/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file Enemy.h
 *
 * @brief description of Enemy behavior.
 */

#ifndef MYENEMY_H
#define MYENEMY_H

#include "start/car.h"

 /// @brief The Car class is the Car implementation.
class Enemy : public Car {
public:
	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENEMY_H */
