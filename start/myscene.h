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
#include <rt2d/text.h>
#include "basicentity.h"

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
	Player* player;
	Enemy* enemy;
	Coin* coin;

	Text* timerText;

	//BasicEntity* background;

	Sprite* background_gray;
	PixelBuffer* bg_gray;

	Point2 checkPoint1;
	Point2 checkPoint2;
	Point2 checkPoint3;
	Point2 checkPoint4;

	Point2 finish;

	bool checkPoint1Check;
	bool checkPoint2Check;
	bool checkPoint3Check;
	bool checkPoint4Check;

	bool finishCheck;

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
	void checkpointCheck();
	void finishCol();
	void finished();

	Timer t;
	float endTime;

protected:
	unsigned int top_layer;
	unsigned int bottom_layer;
	std::vector<Text*> text;
	std::vector<BasicEntity*> layers;
};

#endif /* SCENE00_H */
