#include "SceneManager.h"

namespace BreakoutGame
{
	SceneManager::SceneManager()
	{
		scene = Scene::MENU;
	}

	SceneManager::~SceneManager()
	{

	}

	Scene SceneManager::getScene()
	{
		return scene;
	}

	void SceneManager::setScene(Scene _scene)
	{
		scene = _scene;
	}
}