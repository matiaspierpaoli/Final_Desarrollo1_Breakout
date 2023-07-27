#pragma once
#include "ScreenProperties.h"
#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Game.h"
#include "Credits.h"

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