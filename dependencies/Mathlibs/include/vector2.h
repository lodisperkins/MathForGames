#pragma once

class Vector2
{
private:
	float xpos;
	float ypos;
public:
	Vector2();
	Vector2(float newX, float newY);
	float getX();
	float getY();
	Vector2 operator +(Vector2& rhs);
	Vector2 operator - (Vector2& rhs);
	bool operator == (Vector2& rhs);
	bool operator != (Vector2& rhs);
	float magnitude();
	Vector2 operator* (float&);
	Vector2 normalize();
	float dotproduct(Vector2&rhs);
	float distance(Vector2& rhs);
};