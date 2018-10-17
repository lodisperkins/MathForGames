#include "CDDS_FiniteStateMachine_StudentApp.h"

int main() {
	
	// allocation
	auto app = new CDDS_FiniteStateMachine_StudentApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}