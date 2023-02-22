#include "SceneManager.h"

SceneManager::SceneManager()
{

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