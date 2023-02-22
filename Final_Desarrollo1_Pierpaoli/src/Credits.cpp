#include "Credits.h"

Credits::Credits(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	exitBox.width = 120;
	exitBox.height = 50;
	exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
	exitBox.y = GetScreenHeight() - 100;
}

Credits::~Credits()
{

}

void Credits::UpdateAndDraw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), exitBox)) DrawText("Exit", exitBox.x, exitBox.y, 50, RED);
	else  DrawText(FormatText("Exit"), exitBox.x, exitBox.y, 50, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::MENU);

	EndDrawing();
}