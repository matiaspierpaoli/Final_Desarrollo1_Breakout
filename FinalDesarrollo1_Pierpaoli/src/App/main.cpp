#include "App.h"

// Main basico con un objeto aplicacion y su llamada a su unico metodo, posteriormente la eliminacion del mismo en memoria dinamica
int main()
{
	BreakoutGame::App* app = new BreakoutGame::App();
	app->start();
	delete app;
	return 0;
}