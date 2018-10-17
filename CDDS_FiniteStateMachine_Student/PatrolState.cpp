#include "PatrolState.h"

PatrolState::PatrolState()
{
}

PatrolState::~PatrolState()
{
}

void PatrolState::onUpdate(GameObject * object, float dt)
{
	Vector2D target = m_waypoints[m_currentWaypoint];
	Vector2D pos = object->getPosition();
	Vector2D dist = { target.x - pos.x, target.y - pos.y };
	float mag = sqrt(dist.x *dist.x + dist.y*dist.y);
	if

}
