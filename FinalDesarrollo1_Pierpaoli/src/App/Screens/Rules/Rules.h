#pragma once
#include "raylib.h"
#include "../SceneManager/SceneManager.h"

namespace BreakoutGame
{
	class Rules
	{
	private:
		SceneManager* sceneManager;

		Texture2D texture;

		Rectangle exitBox;
	public:
		Rules(SceneManager* sceneManager);
		~Rules();
		void Draw();
		void Update();
	};
}