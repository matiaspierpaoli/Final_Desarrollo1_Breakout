#include "App.h"


int main()
{
	App* app = new App();
	app->start();
	delete app;
	return 0;
}