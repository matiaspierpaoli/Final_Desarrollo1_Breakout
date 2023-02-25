#include "Rules.h"

Rules::Rules(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	exitBox.width = 120;
	exitBox.height = 50;
	exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
	exitBox.y = GetScreenHeight() - 100;

	texture = LoadTexture("../res/screens/Rules.png");
}

Rules::~Rules()
{
	UnloadTexture(texture);
}

void Rules::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::MENU);
}

void Rules::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}