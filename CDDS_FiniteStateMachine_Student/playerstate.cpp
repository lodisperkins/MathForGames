#include "playerstate.h"

PlayerControlledState::PlayerControlledState()
{
}

PlayerControlledState::~PlayerControlledState()
{
}

void PlayerControlledState::onUpdate(GameObject * object, float deltatime)
{
	aie::Input * input = aie::Input::getInstance();

	float rot = object->getRotation();
	float speed = object->getSpeed();
	Vector2D pos = object->getPosition();
	Vector2D vel = { 0,0 };
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		vel = { cos(rot)*speed*deltatime,sin(rot)*speed*deltatime };
		object->setPosition({ pos.x + vel.x, pos.y + vel.y });
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		rot += RADIANS * speed*deltatime;
		object->setRotation(rot);
	}
	if(input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		rot -= RADIANS * speed*deltatime;
		object->setRotation(rot);
	}
}
