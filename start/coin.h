/**
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 *
 * @file coin.h
 *
 * @brief description of Coin behavior.
 */

#ifndef MYCOIN_H
#define MYCOIN_H

#include <rt2d/entity.h>

 /// @brief The Coin class is the Coin implementation.
class Coin : public Entity {
public:
	/// @brief Constructor
	Coin();
	/// @brief Destructor
	virtual ~Coin();

	bool colCheck;
	bool deleteCoin;

	int coinCounter;

	int time;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	void CoinScore();
};

#endif /* COIN_H */
