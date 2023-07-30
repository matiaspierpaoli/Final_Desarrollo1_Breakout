#pragma once
#include "Screens/ScreenProperties.h"
#include "Screens/SceneManager/SceneManager.h"
#include "Screens/Menu/Menu.h"
#include "Screens/Rules/Rules.h"
#include "Game/Game.h"
#include "Screens/Credits/Credits.h"

namespace BreakoutGame
{
	class App
	{
	private:
		SceneManager* sceneManager;
		Menu* menu;
		Rules* rules;
		Game* game;
		Credits* credits;

		bool shouldExit;

	public:
		App();
		~App();
		void start();
		Music music;
	};
}