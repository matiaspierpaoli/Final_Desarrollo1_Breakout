#pragma once
//#include <Windows.h>
#include "raylib.h"
#include "URLOpener.h"

#include "SceneManager.h"
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

