/**
 * This class describes MyScene behavior.
 *
 * Copyright 2017 Dani Steunebrink <danisteunebrink@live.nl>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{	
	player = new Player();
	enemy = new Enemy();
	coin = new Coin();
	coin2 = new Coin();
	timerText = new Text();
	endTimerText = new Text();
	coinCounter = new Text();
	forgotCheckpoint = new Text();
	endText = new Text();
	deadText = new Text();

	resetText = new Text();
	player->scale = Point(2.0f, 2.0f);
	enemy->scale = Point(2.0f, 2.0f);
	timerText->scale = Point2(0.5f, 0.5f);
	coinCounter->scale = Point2(0.5f, 0.5f);
	endTimerText->scale = Point2(0.5f, 0.5f);
	resetText->scale = Point2(0.8f, 0.8f);

	rCircle = 135.0f;

	this->addSprite("assets/background.tga");
	// create the scene 'tree'
	// add player and enemy to this Scene as a child.


	background_gray = new Sprite();
	background_gray->setupSpriteTGAPixelBuffer("assets/background_gray.tga", 0, 2);
	bg_gray = background_gray->texture()->pixels();

	startRace();
}


MyScene::~MyScene()
{

	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);
	this->removeChild(coin);
	this->removeChild(coin2);
	this->removeChild(timerText);
	this->removeChild(endTimerText);
	this->removeChild(coinCounter);
	this->removeChild(forgotCheckpoint);
	this->removeChild(endText);
	this->removeChild(deadText);
	this->removeChild(resetText);

	// delete player, enemy and coin from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
	delete coin;
	delete coin2;
	delete timerText;
	delete endTimerText;
	delete coinCounter;
	delete forgotCheckpoint;
	delete endText;
	delete deadText;
	delete resetText;
}

void MyScene::update(float deltaTime)
{
	timerText->position = Point2(camera()->position.x + 50 - SWIDTH / 2, camera()->position.y + 50  - SHEIGHT / 2);
	timerText->message("Time: " + std::to_string(int(t.seconds())));

	endTimerText->position = Point2(camera()->position.x + 50 - SWIDTH / 2, camera()->position.y + 110 - SHEIGHT / 2);
	endTimerText->message("Best Time: " + std::to_string(int(endTime)));

	coinCounter->position = Point2(camera()->position.x + 50 - SWIDTH / 2, camera()->position.y + 170 - SHEIGHT / 2);
	coinCounter->message("Coins: " + std::to_string(score) + "/2");

	forgotCheckpoint->position = Point2(camera()->position.x + 150 - SWIDTH / 2, camera()->position.y + 350 - SHEIGHT / 2);

	endText->position = Point2(camera()->position.x + 30 - SWIDTH / 2, camera()->position.y + 350 - SHEIGHT / 2);
	
	deadText->position = Point2(camera()->position.x + 210 - SWIDTH / 2, camera()->position.y + 350 - SHEIGHT / 2);
	
	resetText->position = Point2(camera()->position.x + 390 - SWIDTH / 2, camera()->position.y + 400 - SHEIGHT / 2);

	checkpointCol();
	playerCol();
	checkpointCheck();
	finishCol();
	finished();
	if (spaceCheck == true) {
		if (input()->getKeyDown(KeyCode::Space)) {

			endText->message("");
			resetText->message("");
			deadText->message("");

			this->removeChild(player);
			this->removeChild(enemy);
			this->removeChild(coin);
			this->removeChild(coin2);
			this->removeChild(timerText);
			this->removeChild(endTimerText);
			this->removeChild(coinCounter);
			this->removeChild(forgotCheckpoint);
			this->removeChild(endText);
			this->removeChild(deadText);
			this->removeChild(resetText);

			startRace();
		}
	}

	if (coin->deleteCoin == true) {
		player->sprite()->color = RED;
		this->removeChild(coin);
		col = true;
		score++;
		coin->deleteCoin = false;
	}

	if (coin2->deleteCoin == true) {
		player->sprite()->color = RED;
		this->removeChild(coin2);
		col = true;
		score++;
		coin2->deleteCoin = false;
	}

	x = player->position.x + 2048;
	y = player->position.y + 2048;

	y -= 4096;
	y *= -1;

	unsigned char tint = bg_gray->data[getindex(x, y, 4096, 4096) * 4]; // alpha pixel

	if (tint == 255) {
		player->velocityCheck = false;
	}
	else {
		player->velocityCheck = true;
	}

	counter += bg_gray->bitdepth;
	tcounter++;

	camera()->position.x = player->position.x;
	camera()->position.y = player->position.y;


	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

int MyScene::getindex(int x, int y, int w, int h) {
	if (x >= 0 && x < w && y >= 0 && y < h) {
		int i = (y * w) + x;
		return i;
	}
	return -1;
}

void MyScene::playerCol() {

	if (player->sprite()->size.y / 4 + coin->sprite()->size.y / 2 > sqrt(Vector3(player->position - coin->position).x * Vector3(player->position - coin->position).x + (Vector3(player->position - coin->position).y * Vector3(player->position - coin->position).y))) { //true if overlapping
		coin->colCheck = true;
	}



	if (player->sprite()->size.y / 4 + coin2->sprite()->size.y / 2 > sqrt(Vector3(player->position - coin2->position).x * Vector3(player->position - coin2->position).x + (Vector3(player->position - coin2->position).y * Vector3(player->position - coin2->position).y))) { //true if overlapping
		coin2->colCheck = true;
	}


	if (player->sprite()->size.y / 4 + enemy->sprite()->size.y / 2 > sqrt(Vector3(player->position - enemy->position).x * Vector3(player->position - enemy->position).x + (Vector3(player->position - enemy->position).y * Vector3(player->position - enemy->position).y))) { //true if overlapping

		player->stopMovement = true;

		this->removeChild(player);
		this->removeChild(enemy);

		deadText->message("You have crashed your car");
		resetText->message("Press space to reset");
		spaceCheck = true;
	}
	else {
		addScore = true;
		player->sprite()->color = RED;
	}
}

void MyScene::checkpointCol() {

	Point dist1 = player->position - checkPoint1;
	Point dist2 = player->position - checkPoint2;
	Point dist3 = player->position - checkPoint3;
	Point dist4 = player->position - checkPoint4;

	if (sqrt((dist1.x * dist1.x) + (dist1.y * dist1.y)) <= rCircle) {
		checkPoint1Check = true;
	}

	if (sqrt((dist2.x * dist2.x) + (dist2.y * dist2.y)) <= rCircle) {
		checkPoint2Check = true;
	}

	if (sqrt((dist3.x * dist3.x) + (dist3.y * dist3.y)) <= rCircle) {
		checkPoint3Check = true;
	}

	if (sqrt((dist4.x * dist4.x) + (dist4.y * dist4.y)) <= rCircle) {
		checkPoint4Check = true;
	}
}

void MyScene::finishCol() {

	Point distF = player->position - finish;

	if (sqrt((distF.x * distF.x) + (distF.y * distF.y)) <= rCircle) {
		if (checkPoint4Check == true && checkPoint3Check == true && checkPoint2Check == true && checkPoint1Check == true) {
			finishCheck = true;
		}

		if (checkPoint4Check == false && checkPoint3Check == true && checkPoint2Check == true && checkPoint1Check == true) {
			forgotCheckpoint->message("you forgot the fourth checkpoint");
			checkPoint4Check = false;
		}
	}
}

void MyScene::finished() {
	if (checkPoint1Check == true && checkPoint2Check == true && checkPoint3Check == true && checkPoint4Check == true) {
		if (finishCheck == true) {
			if (laps == 3) {
				if (endTime >= t.seconds() || endTime == 0) {
					endTime = t.seconds();

					if (score == 1) {
						endTime -= 1;
					}
					else if (score == 2) {
						endTime -= 2;
					}
				}

				checkPoint1Check = false;
				checkPoint2Check = false;
				checkPoint3Check = false;
				checkPoint4Check = false;

				t.stop();
				endText->message("You finished! your best time is: " + std::to_string(int(endTime)) + " sec");
				resetText->message("Press space to reset");

				enemy->direction(Point2(0, -100));

				player->stopMovement = true;
				enemy->stopEnemyMovement = true;
				spaceCheck = true;
				finishCheck = false;
			}
			else {
				laps++;
				if (endTime >= t.seconds() || endTime == 0) {
					endTime = t.seconds();

					if (score == 1) {
						endTime -= 1;
					}
					else if (score == 2) {
						endTime -= 2;
					}
				}

				t.stop();

				checkPoint1Check = false;
				checkPoint2Check = false;
				checkPoint3Check = false;
				checkPoint4Check = false;

				finishCheck = false;

				t.start();
			}
		}
	}
}

void MyScene::checkpointCheck() {

	if (checkPoint2Check == true && checkPoint1Check == false) {
		checkPoint2Check = false;
		forgotCheckpoint->message("you forgot the first checkpoint");
	}
	else if (checkPoint3Check == true && checkPoint1Check == false) {
		checkPoint2Check = false;
		checkPoint3Check = false;
		forgotCheckpoint->message("you forgot the first checkpoint");
	}
	else if (checkPoint4Check == true && checkPoint1Check == false) {
		checkPoint2Check = false;
		checkPoint3Check = false;
		checkPoint4Check = false;
		forgotCheckpoint->message("you forgot the first checkpoint");
	}
	else if (checkPoint2Check == false && checkPoint3Check == true) {
		checkPoint3Check = false;
		forgotCheckpoint->message("you forgot the second checkpoint");
	}
	else if (checkPoint2Check == false && checkPoint4Check == true) {
		checkPoint3Check = false;
		checkPoint4Check = false;
		forgotCheckpoint->message("you forgot the second checkpoint");
	}
	else if (checkPoint3Check == false && checkPoint4Check == true) {
		checkPoint4Check = false;
		forgotCheckpoint->message("you forgot the third checkpoint");
	}
	else {
		
		forgotCheckpoint->message("");
	}
}

void MyScene::startRace() {

	t.start();

	endTime = 0.0f;
	laps = 0;
	score = 0;
	
	coinCounter->message("Coins: " + std::to_string(score) + "/2");

	this->addChild(player);
	this->addChild(enemy);
	this->addChild(coin);
	this->addChild(coin2);
	this->addChild(timerText);
	this->addChild(endTimerText);
	this->addChild(coinCounter);
	this->addChild(forgotCheckpoint);
	this->addChild(endText);
	this->addChild(deadText);
	this->addChild(resetText);

	enemy->direction(Point2(0, -100));
	enemy->time = 0;

	player->position = Point(-1100, 300);
	enemy->position = Point(-1000, 300);
	coin->position = Point(700, -1100);
	coin2->position = Point(1000, -130);

	checkPoint1 = Point2(-1300, -1200);
	checkPoint2 = Point2(950, -1300);
	checkPoint3 = Point2(1400, 200);
	checkPoint4 = Point2(-950, 1220);

	checkPoint1Check = false;
	checkPoint2Check = false;
	checkPoint3Check = false;
	checkPoint4Check = false;
	finishCheck = false;
	spaceCheck = false;
	coin->deleteCoin = false;
	coin2->deleteCoin = false;
	coin->colCheck = false;
	coin2->colCheck = false;
	player->stopMovement = false;
	enemy->stopEnemyMovement = false;

	coin->scale = Point2(1.0f, 1.0f);
	coin2->scale = Point2(1.0f, 1.0f);

	finish = Point2(-1000, 300);

	col = false;

	addScore = true;

	counter = 0;
	tcounter = 0;

	x = 0;
	y = 0;
}
