/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "enemy.h"
#include "coin.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{

public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	float dist(Vector2 entity1, Vector2 entity2);

	int getindex(int x, int y, int w, int h);

private:
	/// @brief the rotating square in the middle of the screen
	Player* player;
	Enemy* enemy;
	Coin* coin;

	Sprite* background_gray;
	PixelBuffer* bg_gray;

	Point2 checkPoint1;
	Point2 checkPoint2;
	Point2 checkPoint3;
	Point2 checkPoint4;

	float rCircle;

	bool addScore;

	bool col;

	int counter;
	int tcounter;
	int x;
	int y;

	int score;

	void checkpointCol();

	void playerCol();
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
