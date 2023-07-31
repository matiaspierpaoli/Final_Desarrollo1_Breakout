#include "Credits.h"

namespace BreakoutGame
{
	Credits::Credits(SceneManager* _sceneManager)
	{
		sceneManager = _sceneManager; // Manager de credits = manager de app

		exitBox.width = 120;
		exitBox.height = 50;
		exitBox.x = GetScreenWidth() / 2 - exitBox.width / 2;
		exitBox.y = static_cast<float>(GetScreenHeight() - 100);

		musicURLBox.width = 370;
		musicURLBox.height = 33;
		musicURLBox.x = GetScreenWidth() / 2 - musicURLBox.width / 2;
		musicURLBox.y = static_cast<float>(GetScreenHeight() - 250);

		texture = LoadTexture("res/screens/Credits.png");

		musicVideoURL = "https://www.youtube.com/watch?v=l7SwiFWOQqM&ab_channel=FreeMusic";
	}

	Credits::~Credits()
	{
		UnloadTexture(texture);
	}

	void Credits::Update()
	{
		if (CheckCollisionPointRec(GetMousePosition(), exitBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) sceneManager->setScene(Scene::MENU);
		if (CheckCollisionPointRec(GetMousePosition(), musicURLBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) urlOpener.OpenURL(musicVideoURL);
	}

	void Credits::Draw()
	{
		BeginDrawing();
		DrawTexture(texture, 0, 0, WHITE);
		EndDrawing();
	}
}