#pragma once
#include"State.h"
#include"Input.h"
#include"GameObject.h"
#include "GameDefs.h"
class PlayerControlledState : public State
{
public:
	PlayerControlledState();
	~PlayerControlledState();

	void onUpdate(GameObject*object, float deltatime);
};