#pragma once

class Vector4
{
private:
	float xpos;
	float ypos;
	float zpos;
	float trans;
public:
	Vector4();
	Vector4(float newX, float newY, float newZ,float newT);
	float getX();
	float getY();
	float getZ();
	float getT();
	Vector4 operator +(Vector4& rhs);
	Vector4 operator - (Vector4& rhs);
	bool operator == (Vector4& rhs);
	bool operator != (Vector4& rhs);
	float magnitude();
	Vector4 operator* (float&);
	Vector4 normalize();
	float dotproduct(Vector4&rhs);
	float distance(Vector4& rhs);
};