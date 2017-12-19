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

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	enemy = new Enemy();
	//myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	player->scale = Point(2.0f, 2.0f);
	enemy->scale = Point(2.0f, 2.0f);
	
	player->position = Point(-1000, 300);
	enemy->position = Point(-1000, 300);

	//this->addSprite("assets/background_gray.tga");
	this->addSprite("assets/background.tga");
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
}

void MyScene::update(float deltaTime)
{

	//background_gray = new Sprite();
	//background_gray->setupSpriteTGAPixelBuffer("assets/heightmap256.tga", 0, 2);
	//PixelBuffer* bg_gray = background_gray->texture()->pixels();

	//Point2 offset = Point2(-100, -100);
	//for (int i; ) {
	//		unsigned char tint = bg_gray->data[+ 3]; // alpha pixel
	//}

	if (player->position.x) {

	}

	camera()->position.x = player->position.x;
	camera()->position.y = player->position.y;


	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = player->sprite()->color;
		player->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
