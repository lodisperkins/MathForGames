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

	glm::mat4	m_viewMatrix;
	glm::mat4 tank;
	glm::mat4 tank_Rot;
	glm::vec4 moveright;
	glm::vec4 moveleft;
	glm::vec4 moveForward;
	glm::vec4 moveBackward;
	glm::vec3 cannonPos;
	glm::vec3 turretPos;
	glm::mat4 world;
	glm::mat4* tankptr;
	glm::mat4* cannonPtr;
	glm::mat4*turretptr;
	glm::mat4 tank_Trans;
	float rotateVal;
	float xCam = 0;
	float zCam=10;
	glm::mat4 cannon;
	glm::mat4 turret;
	glm::mat4 turret_Rot;
	glm::mat4 cannon_Rot;
	glm::mat4* ptrcannon;
	
	glm::mat4	m_projectionMatrix;
};