| Lodis Perkins|
| :---          	|
| s188043       	|
| Math for Games |
| Test Program Documentation |

## I. Requirements

1. **Description of Problem**

      **Name**:  Tank Test Program

      **Problem Statement**:

      Draw a top-down 2D tank, and manipulate its orientation and position using your math library in response to keyboard
input from the user.

     **Problem Specifications**:  
     - Your project opens a graphic display window and draws a tank.

	 - The tank’s position and orientation is calculated using the functions and classes included in your maths library or OpenGL mathematics library.
	 - The turret rotates correctly
	 - A matrix hierarchy is correctly implemented (moving the tank base affects the position/orientation of the turret; the bullet is not affected by changes in either the turret or tank base)
	 - The bullet spawns at the correct position and travels in the direction the turret is pointing
	 - Readme is provided detailing intended use of application. Information provided includes but not limited to 1. Steps the end user is to follow to reproduce the grade you want. 2. Instructions on how to interact with application.


1. **Input Information**
   
   W- Moves the tank up

   S - Moves the tank down

   A - Moves the tank left

   D - Moves the tank right

   E- Rotates tank counter clockwise

   Q - Rotates tank clockwise

   L - Rotates turret counter clockwise

   J- Rotates turret clockwise

   O- Fires a bullet from the cannon

2.  **Output Information**  
    - The program displays a simulation of the movements of a tank
## II. Design

1. _System Architecture_

	The program uses the AIE Bootstrap to draw and manipulate its elements. All code for the tank is located in application3D.h and application3D.cpp. The header file is where the matrices that represent the tanks location, rotation, and translation are declared. The source file is where the matrices are manipulated using bootstraps update function to provide movement of the tank overtime.


2. _Object Information_
   
	- **File Name**: Application3D.cpp
		- Name: world(mat4)
			- Description: The identity matrix
        - Name: tank(mat4)
			- Description: Matrix that is responsible for keeping track of the tanks position and orientation
  		- Name: turret(mat4)
			- Description: Matrix that is responsible for keeping track of the turrets position and orientation
		- Name: cannon(mat4)
			- Description: Matrix that is responsible for keeping track of the cannons position and orientation
        - Name: bullet(mat4)
			- Description: Matrix that is responsible for keeping track of the bullets position and orientation
        - Name: tank_Trans(mat4)
			- Description: Matrix that is used to increase or decrease the tank's position in relation to the identity matrix
        - Name: turret_Trans(mat4)
			- Description: Matrix that is used to increase or decrease the turret's position in relation to the tank's matrix
        - Name: cannon_Trans(mat4)
			- Description: Matrix that is used to increase or decrease the cannon's position in relation to the turret's matrix
        - Name: bullet_Trans(mat4)
			- Description: Matrix that is used to increase or decrease the bullet's position in relation to the cannon's matrix
        - Name: tank_Rot(mat4)
			- Description: Matrix that is used to rotate the tank in relation to the identity matrix
        - Name: turret_Rot(mat4)
			- Description: Matrix that is used to rotate the turret in relation to the tank's matrix
        - Name: cannon_Rot(mat4)
			- Description: Matrix that is used to rotate the cannon in relation to the turret's matrix
        - Name: tankptr(mat4*)
			- Description: Matrix pointer used in the Gizmos addAABBFilled function to draw the base of the tank
        - Name: turretptr(mat4*)
			- Description: Matrix pointer used in the Gizmos addSphere function to draw the turret on top of the tank
        - Name: cannonptr(mat4*)
			- Description: Matrix pointer used in the Gizmos addCylinderFilled function to draw a cannon horizontal to the turret
        - Name: bulletptr(mat4*)
			- Description: Matrix pointer used in the Gizmos addSphere function to draw a bullet shooting out of the cannon when called
        - Name: bullet_Distance(float)
			- Description: Value to track the distance of the bullet so that despawns at a certain point
            	               	 
## III Implementation Documentation

**Filename**: Application3D.h
```c++
#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>

class Application3D : public aie::Application {
public:

	Application3D();
	virtual ~Application3D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	// project3d matrices
	glm::mat4	m_projectionMatrix;
	glm::mat4	m_viewMatrix;
	//identity matrix
	glm::mat4 world;
	//Tank matrices in decending order 
	glm::mat4 tank;
	glm::mat4 turret;
	glm::mat4 cannon;
	glm::mat4 bullet;
	//Translation matrices responsible for movement of each part of the tank
	glm::mat4 tank_Trans;
	glm::mat4 turret_Trans;
	glm::mat4 cannon_Trans;
	glm::mat4 bullet_Trans;
	//Rotation matrices responsible for rotation of each part of the tank
	glm::mat4 tank_Rot;
	glm::mat4 turret_Rot;
	glm::mat4 cannon_Rot;
	//Pointers for each matrix to be used as the matrix pointer argument for the gizmos draw shape functions
	glm::mat4* tankptr;
	glm::mat4*turretptr;
	glm::mat4* ptrcannon;
	glm::mat4*bulletptr;
	//Value to track the distance of the bullet so that despawns at a certain point
	float bullet_Distance;
};
```
**Filename**: Application3D.cpp
```c++
bool Application3D::startup() {
	
	setBackgroundColour(0.25f, 0.25f, 0.25f);

	// initialise gizmo primitive counts
	Gizmos::create(10000, 10000, 10000, 10000);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
										  getWindowWidth() / (float)getWindowHeight(),
										  0.1f, 1000.f);
	//initialise default values for each of the matrices
	world = mat4(1);
	tank_Rot = mat4(1);
	tank_Trans = mat4(1);
	turret_Rot = mat4(1);
	turret_Trans = mat4(1);
	cannon_Rot = mat4(1);
	//Changes then orientaion of the cannon and bullet so it is positioned horizontally on the turret
	cannon_Rot = glm::rotate(cannon_Rot, 30.f, vec3(0, 0, 1));
	cannon_Trans = glm::translate(mat4(1), vec3(.5, .5, 0));
	bullet_Trans = glm::translate(mat4(1), vec3(.5, .5, 0));
	bullet_Distance = 0;
	return true;
}

void Application3D::update(float deltaTime) {

	// query time since application started
	float time = getTime();
	
	// rotate camera
	m_viewMatrix = glm::lookAt(vec3(0,20,3),vec3(0), vec3(0, 1, 0));
vec4 green(.5f, 0.5f, 0, 1);
	// wipe the gizmos clean for this frame
	Gizmos::clear();
	//Updates the position and orientation of the matrices while respecting the matrix hierarchy
	tank = world*(tank_Trans*tank_Rot);
	turret = tank * (turret_Trans*turret_Rot);
	cannon = turret * (cannon_Trans*cannon_Rot);
	bullet = cannon * bullet_Trans;
	//assigns the pointers to their corresponding matrix
	tankptr = &tank;
	bulletptr = &bullet;
	turretptr = &turret;
	ptrcannon = &cannon;
	//draws the shapes for the tank
	Gizmos::addAABBFilled(tank[3], vec3(2,.5,2), green,tankptr);
	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	Gizmos::addSphere(turret[3], 1.5, 15, 15,green,turretptr);
	Gizmos::addCylinderFilled(cannon[3], .3, 1, 15, green, ptrcannon);

	// draw a simple grid with gizmos
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(vec3(-10 + i, 0, 10),
						vec3(-10 + i, 0, -10),
						i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i),
						vec3(-10, 0, -10 + i),
						i == 10 ? white : black);
	}

	
	aie::Input* input = aie::Input::getInstance();
	//rotates the tank based on the button pressed
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		tank_Rot = glm::rotate(tank_Rot, 0.01f, vec3(0, 1, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		tank_Rot = glm::rotate(tank_Rot, -0.01f, vec3(0, 1, 0));
	}
	//moves the tank in the position desired by the user based on the button pressed
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		tank_Trans = glm::translate(tank_Trans, vec3(0.1, 0, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		tank_Trans = glm::translate(tank_Trans, vec3(0, 0, -0.1));
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		tank_Trans = glm::translate(tank_Trans, vec3(-0.1, 0, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		tank_Trans = glm::translate(tank_Trans, vec3(0, 0, 0.1));
	}
	//rotates the turret in either a counter clockwise or a clockwise direction
	if (input->isKeyDown(aie::INPUT_KEY_L))
	{
		turret_Rot = glm::rotate(turret_Rot,0.01f, vec3(0, 1, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_J))
	{
		turret_Rot = glm::rotate(turret_Rot, -0.01f, vec3(0, 1, 0));
	}
	//draws a sphere representing the bullet and translates it until its distance is 1 unit away from the cannon
	if (input->isKeyDown(aie::INPUT_KEY_O))
	{
		Gizmos::addSphere(bullet[3], .2, 15, 15, green, bulletptr);
		bullet_Trans = glm::translate(bullet_Trans, vec3(0, bullet_Distance, 0));
		if (bullet_Distance <= 1)
		{
			bullet_Distance+=.1;
		}
		else
		{
			bullet_Distance = 0;
			bullet = cannon;
			bullet_Trans = mat4(1);
		}
	}
	// quit if we press escape
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}
};
```
