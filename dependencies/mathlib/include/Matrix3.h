#pragma once
#include "vector3.h"
class Matrix3
{
private:
	float grid[3][3];
public:
	Matrix3();
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	void rotate(float);
	Matrix3 operator * (Matrix3);
	Vector3 operator[] (int);
	Vector3 operator * (Vector3);
};