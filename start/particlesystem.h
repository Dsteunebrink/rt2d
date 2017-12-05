/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file particlesystem.h
 *
 * @brief description of Particle System behavior.
 */

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "start/myscene.h"

 /// @brief The Collectable class is the Particle System implementation.
class ParticleSystem : public MyScene {
public:
	/// @brief Constructor
	ParticleSystem();
	/// @brief Destructor
	virtual ~ParticleSystem();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* PARTICLESYSTEM_H */
