#pragma once
#include "raylib.h"
#include "..\SceneManager\SceneManager.h"

namespace BreakoutGame
{
	class Menu
	{
	private:
		SceneManager* sceneManager;

		Rectangle titleBox;
		Rectangle playBox;
		Rectangle rulesBox;
		Rectangle creditsBox;
		Rectangle exitBox;

		Texture2D texture;

	public:
		Menu(SceneManager* sceneManager);
		~Menu();
		void Draw();
		void Update();
	};
}