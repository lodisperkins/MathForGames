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