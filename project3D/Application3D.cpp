#define GLM_FORCE_SWIZZLE
#include "Application3D.h"
#include "Gizmos.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

Application3D::Application3D() {

}

Application3D::~Application3D() {

}

bool Application3D::startup() {
	
	setBackgroundColour(0.25f, 0.25f, 0.25f);

	// initialise gizmo primitive counts
	Gizmos::create(10000, 10000, 10000, 10000);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
										  getWindowWidth() / (float)getWindowHeight(),
										  0.1f, 1000.f);
	world = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
	tank = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
	tank_Rot = glm::rotate(tank, 0.1f, vec3(0, 1, 0));
	turret = tank;
	turret_Rot = glm::rotate(tank, 0.1f, vec3(0, 1, 0));
	cannon = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
	cannon_Rot = glm::rotate(tank, 0.1f, vec3(0, 1, 0));
	cannon = cannon * cannon_Rot;
	tank = tank * turret * cannon;
	turret = turret * cannon;
	rotateVal = 0;

	return true;
}

void Application3D::shutdown() {

	Gizmos::destroy();
}

void Application3D::update(float deltaTime) {

	// query time since application started
	float time = getTime();
	
	// rotate camera
	m_viewMatrix = glm::lookAt(vec3(0,20,3),vec3(0), vec3(0, 1, 0));
vec4 green(.5f, 0.5f, 0, 1);
	// wipe the gizmos clean for this frame
	Gizmos::clear();
	
	mat4* tankptr = &tank;
	
	mat4* cannonPtr = &cannon;
	
	mat4*turretptr = &turret;
	moveright = { .01,0,0,1 };
	moveleft = { -.01,0,0,1 };
	moveForward = { 0,0,.01,1 };
	moveBackward = { 0,0,-.01,1 };
	
	
	
	Gizmos::addAABBFilled(tank[3], vec3(2,.5,2), green,tankptr);
	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	Gizmos::addSphere(turret[3], 1.5, 15, 15,green,turretptr);
	Gizmos::addCylinderFilled(cannonPos, .3, 1, 15, green,cannonPtr );
	// draw a simple grid with gizmos

	
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(vec3(-10 + i, 0, 10),
						vec3(-10 + i, 0, -10),
						i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i),
						vec3(-10, 0, -10 + i),
						i == 10 ? white : black);
	}

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		tank[3] = tank * moveright;
	
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		tank[3] = tank * moveleft;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		tank[3] = tank * moveBackward;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		tank[3] = tank * moveForward;
	}
	if (input->isKeyDown(aie::INPUT_KEY_L))
	{
		turret = glm::rotate(turret,0.01f, vec3(0, 1, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_J))
	{
		xCam--;
		zCam--;
	}
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application3D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// update perspective in case window resized
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
										  getWindowWidth() / (float)getWindowHeight(),
										  0.1f, 1000.f);

	// draw 3D gizmos
	Gizmos::draw(m_projectionMatrix * m_viewMatrix);

	// draw 2D gizmos using an orthogonal projection matrix (or screen dimensions)
	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());
}