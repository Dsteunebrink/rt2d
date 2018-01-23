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
	Coin* coin2;

	Text* timerText;
	Text* endTimerText;
	Text* coinCounter;
	Text* forgotCheckpoint;
	Text* endText;
	Text* deadText;
	Text* resetText;
	Text* menuText;
	Text* startText;
	Text* infoText;

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
	bool spaceCheck;
	bool addScore;
	bool col;
	bool coinCheck;
	bool enterCheck;

	int counter;
	int tcounter;
	int x;
	int y;
	int laps;
	int score;

	void checkpointCol();
	void playerCol();
	void checkpointCheck();
	void finishCol();
	void finished();
	void startRace();

	Timer t;
	
	float endTime;
	float rCircle;

protected:
};

#endif /* SCENE00_H */
