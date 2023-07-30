#pragma once
#include "raylib.h"
#include "..\..\src\App\URLOpener\URLOpener.h"
#include "..\SceneManager\SceneManager.h"

namespace BreakoutGame
{
	class Credits
	{
	private:
		SceneManager* sceneManager;
		URLOpener urlOpener;

		Texture2D texture;
		Rectangle exitBox;
		Rectangle musicURLBox;

		std::string musicVideoURL;
	public:
		Credits(SceneManager* sceneManager);
		~Credits();
		void Draw();
		void Update();
	};
}