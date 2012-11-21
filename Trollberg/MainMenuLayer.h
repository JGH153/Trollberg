#pragma once 
#include "Pim.h"
#include "MenuButton.h"
#define NUMMENYBUTTONS 4

class MainMenuLayer: public Pim::Layer, public Pim::ButtonCallback
{
public:
	MainMenuLayer();

	void loadResources();

	MenuButton* createButton(int xPos, int yPos, std::string buttonLabel);

	void buttonPressed(Pim::Button*);

	void MainMenuLayer::update(float dt);

private:
	Pim::SpriteBatchNode *buttonSheet;

	Pim::Button *mainButton;

	MenuButton *menuButtonsArray[NUMMENYBUTTONS];

	MenuButton *menuButtonTest;
};