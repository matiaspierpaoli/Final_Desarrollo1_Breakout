#include "Menu.h"

Menu::Menu(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	titleBox.width = 400;
	titleBox.height = 75;
	titleBox.x = GetScreenWidth() / 2 - titleBox.width / 2;
	titleBox.y = 50;

	playBox.width = 150;
	playBox.height = 75;
	playBox.x = GetScreenWidth() / 2 - playBox.width / 2;
	playBox.y = GetScreenHeight() / 2 - 100;

	exitBox.width = 150;
	exitBox.height = 75;
	exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
	exitBox.y = GetScreenHeight() - 180;
}

Menu::~Menu()
{

}

void Menu::UpdateAndDraw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawText("Breakout ", titleBox.x, titleBox.y, 100, RED);

	if (CheckCollisionPointRec(GetMousePosition(), playBox)) DrawText("Play", playBox.x, playBox.y, 80, RED);
	else  DrawText(FormatText("Play"), playBox.x, playBox.y, 80, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), exitBox)) DrawText("Exit", exitBox.x, exitBox.y, 80, RED);
	else  DrawText(FormatText("Exit"), exitBox.x, exitBox.y, 80, WHITE);


	if (CheckCollisionPointRec(GetMousePosition(), playBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::GAMEPLAY);
	if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::EXIT);

	EndDrawing();
}