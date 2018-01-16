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
	// start the timer.
	t.start();

	endTime = 0.0f;

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	enemy = new Enemy();
	coin = new Coin();
	timerText = new Text();
	endTimerText = new Text();
	forgotCheckpoint = new Text();

	//myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	player->scale = Point(2.0f, 2.0f);
	enemy->scale = Point(2.0f, 2.0f);
	timerText->scale = Point2(0.5f, 0.5f);
	endTimerText->scale = Point2(0.5f, 0.5f);

	player->position = Point(-1100, 300);
	enemy->position = Point(-1000, 300);
	coin->position = Point(-1400, -500);

	checkPoint1 = Point2(-1300, -1200);
	checkPoint2 = Point2(950, -1300);
	checkPoint3 = Point2(1400, 200);
	checkPoint4 = Point2(-950, 1220);

	checkPoint1Check = false;
	checkPoint2Check = false;
	checkPoint3Check = false;
	checkPoint4Check = false;
	finishCheck = false;

	finish = Point2(-1000, 300);

	col = false;

	rCircle = 130.0f;

	addScore = true;



	this->addSprite("assets/background.tga");
	// create the scene 'tree'
	// add player and enemy to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
	this->addChild(coin);
	this->addChild(timerText);
	this->addChild(endTimerText);
	this->addChild(forgotCheckpoint);

	background_gray = new Sprite();
	background_gray->setupSpriteTGAPixelBuffer("assets/background_gray.tga", 0, 2);
	bg_gray = background_gray->texture()->pixels();

	counter = 0;
	tcounter = 0;

	x = 0;
	y = 0;
}


MyScene::~MyScene()
{

	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);
	this->removeChild(coin);
	this->removeChild(timerText);
	this->removeChild(endTimerText);
	this->removeChild(forgotCheckpoint);

	// delete player, enemy and coin from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
	delete coin;
	delete timerText;
	delete endTimerText;
	delete forgotCheckpoint;
}

void MyScene::update(float deltaTime)
{
	timerText->position = Point2(camera()->position.x + 50 - SWIDTH / 2, camera()->position.y + 50  - SHEIGHT / 2);
	timerText->message("Time: " + std::to_string(int(t.seconds())));

	endTimerText->position = Point2(camera()->position.x + 50 - SWIDTH / 2, camera()->position.y + 110 - SHEIGHT / 2);
	endTimerText->message("Best Time: " + std::to_string(int(endTime)));

	forgotCheckpoint->position = Point2(camera()->position.x + 150 - SWIDTH / 2, camera()->position.y + 350 - SHEIGHT / 2);

	checkpointCol();
	playerCol();
	checkpointCheck();
	finishCol();
	finished();

	if (coin->deleteCoin == true) {
		player->sprite()->color = RED;
		this->removeChild(coin);
		col = true;
		coin->deleteCoin = false;
	}

	std::cout << t.seconds() << std::endl;

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



	if (col == false) {
		if (player->sprite()->size.y / 4 + coin->sprite()->size.y / 2 > sqrt(Vector3(player->position - coin->position).x * Vector3(player->position - coin->position).x + (Vector3(player->position - coin->position).y * Vector3(player->position - coin->position).y))) { //true if overlapping
			coin->colCheck = true;
			if (addScore == true) {
				score++;
				addScore = false;
			}
		}
	}

	if (player->sprite()->size.y / 4 + enemy->sprite()->size.y / 2 > sqrt(Vector3(player->position - enemy->position).x * Vector3(player->position - enemy->position).x + (Vector3(player->position - enemy->position).y * Vector3(player->position - enemy->position).y))) { //true if overlapping
		player->sprite()->color = BLUE;

		//this->removeChild(player);
		//this->removeChild(enemy);
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

			if (endTime >= t.seconds() || endTime == 0) {

				endTime = t.seconds();
			}

			std::cout << endTime << std::endl;
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
