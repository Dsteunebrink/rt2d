/**
* Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
*
* @file particle.h
*
* @brief description of Particle behavior.
*/

#ifndef PARTICLE_H
#define PARTICLE_H

#include "start/particlesystem.h"
#include "start/myentity"

/// @brief The Collectable class is the Particle implementation.
class Particle : public ParticeSystem {
public:
	/// @brief Constructor
	Particle();
	/// @brief Destructor
	virtual ~Particle();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* PARTICLE_H */
