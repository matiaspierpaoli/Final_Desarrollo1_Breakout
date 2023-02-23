#include "Credits.h"

Credits::Credits(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;

	exitBox.width = 120;
	exitBox.height = 50;
	exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
	exitBox.y = GetScreenHeight() - 100;

	texture = LoadTexture("../res/Credits.png");
}

Credits::~Credits()
{
	UnloadTexture(texture);
}

void Credits::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::MENU);
}

void Credits::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}