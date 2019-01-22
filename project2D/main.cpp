#include "Application2D.h"
#include <vector2.h>
#include "CDDS_BinaryTreesApp.h"
int main() {
	
	// allocation
	auto app = new CDDS_BinaryTreesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);
	Vector2 thing;
	// deallocation
	delete app;

	return 0;
}