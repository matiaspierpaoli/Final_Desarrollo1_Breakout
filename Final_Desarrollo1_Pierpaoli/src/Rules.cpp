#include "Rules.h"

Rules::Rules(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	exitBox.width = 150;
	exitBox.height = 75;
	exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
	exitBox.y = GetScreenHeight() - 180;
}

Rules::~Rules()
{

}

void Rules::DrawAndUpdate()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), exitBox)) DrawText("Exit", exitBox.x, exitBox.y, 80, RED);
	else  DrawText(FormatText("Exit"), exitBox.x, exitBox.y, 80, WHITE);

	if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::MENU);

	EndDrawing();
}