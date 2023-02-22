#include "Menu.h"

Menu::Menu(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	playBox.width = 150;
	playBox.height = 75;
	playBox.x = GetScreenWidth() / 2 - 100;
	playBox.y = GetScreenHeight() / 2 - 100;

	exitBox.width = 150;
	exitBox.height = 75;
	exitBox.x = GetScreenWidth() / 2 - 100;
	exitBox.y = GetScreenHeight() - 200;
}

Menu::~Menu()
{

}

void Menu::Update()
{

}

void Menu::Draw()
{

}