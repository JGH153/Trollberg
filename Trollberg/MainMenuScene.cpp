#pragma once 
#include "MainMenuScene.h"
#include "GameScene.h"
#include "MainMenuLayer.h"



MainMenuScene::MainMenuScene(float ambientPos)
{
	ambientRain			= NULL;
	ambientStartPos		= ambientPos;
}
MainMenuScene::~MainMenuScene()
{
	if (ambientRain)
	{
		delete ambientRain;
	}
}

void MainMenuScene::loadResources()
{
	color = Pim::Color(0.207, 0.537, 0.647, 1.f);

	addLayer(new MainMenuLayer());

	// Load the rain-sound
	ambientRain = new Pim::Sound("res\\ambientrain.ogg");
	ambientRain->position(ambientStartPos);
	ambientRain->setVolume(0.8f);
	ambientRain->loop();

#ifndef _DEBUG
	// Maximize the window in release builds
	HWND hwnd = Pim::GameControl::getSingleton()->getRenderWindow()->getHwnd();
	SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
#endif
}

void MainMenuScene::startGame()
{
	Pim::GameControl::getSingleton()->setScene(new GameScene(1, ambientRain->position()));
}

void MainMenuScene::update(float dt)
{

}
