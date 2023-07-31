#include "Menu.h"


namespace BreakoutGame
{
	Menu::Menu(SceneManager* _sceneManager)
	{
		sceneManager = _sceneManager; // Manager de menu = manager de app

		titleBox.width = 450;
		titleBox.height = 75;
		titleBox.x = static_cast<float>(GetScreenWidth() / 2 - titleBox.width / 2);
		titleBox.y = 50;

		playBox.width = 180;
		playBox.height = 75;
		playBox.x = static_cast<float>(GetScreenWidth() / 2 - playBox.width / 2);
		playBox.y = static_cast<float>(GetScreenHeight() / 2 - 100);

		rulesBox.width = 230;
		rulesBox.height = 75;
		rulesBox.x = static_cast<float>(GetScreenWidth() / 2 - rulesBox.width / 2);
		rulesBox.y = static_cast<float>(GetScreenHeight() / 2);

		creditsBox.width = 300;
		creditsBox.height = 75;
		creditsBox.x = static_cast<float>(GetScreenWidth() / 2 - creditsBox.width / 2);
		creditsBox.y = static_cast<float>(GetScreenHeight() / 2 + 100);

		exitBox.width = 120;
		exitBox.height = 50;
		exitBox.x = static_cast<float>(GetScreenWidth() / 2 - exitBox.width / 2);
		exitBox.y = static_cast<float>(GetScreenHeight() - 100);

		texture = LoadTexture("res/screens/MainMenu.png");
	}

	Menu::~Menu()
	{
		UnloadTexture(texture);
	}

	void Menu::Update()
	{
		if (CheckCollisionPointRec(GetMousePosition(), playBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::GAMEPLAY);
		if (CheckCollisionPointRec(GetMousePosition(), rulesBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::RULES);
		if (CheckCollisionPointRec(GetMousePosition(), creditsBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::CREDITS);
		if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::EXIT);
	}

	void Menu::Draw()
	{
		BeginDrawing();
		DrawTexture(texture, 0, 0, WHITE);
		EndDrawing();
	}
}