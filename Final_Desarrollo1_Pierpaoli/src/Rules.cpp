#include "Rules.h"

Rules::Rules(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}

Rules::~Rules()
{

}

void Rules::DrawAndUpdate()
{
	BeginDrawing();

	ClearBackground(BLACK);

	EndDrawing();
}