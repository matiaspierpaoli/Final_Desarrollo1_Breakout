#include "SceneManager.h"

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

void SceneManager::setScene(Scene scene)
{
	this->scene = scene;
}