#pragma once
#include"State.h"
#include "Vector2D.h"
#include <vector>
#include "GameObject.h"
class PatrolState :public State
{
private:
	std::vector<Vector2D> m_waypoints;
	int m_currentWaypoint;
public:
	PatrolState();
	~PatrolState();

	void onUpdate(GameObject* object, float dt);

	void addWaypoint(Vector2D pos)
	{
		m_waypoints.push_back(pos);
	}
};