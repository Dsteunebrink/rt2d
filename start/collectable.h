/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file collectable.h
 *
 * @brief description of Collectable behavior.
 */

#ifndef MYCOLLECTABLE_H
#define MYCOLLECTABLE_H

#include "start/myscene.h"

 /// @brief The Collectable class is the Collectable implementation.
class Collectable : public MyScene {
public:
	/// @brief Constructor
	Collectable();
	/// @brief Destructor
	virtual ~Collectable();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYCOLLECTABLE_H */
