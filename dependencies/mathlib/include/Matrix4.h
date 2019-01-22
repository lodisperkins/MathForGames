#pragma once
#include "vector4.h"
class Matrix4
{
private:
	float grid[4][4];
public:
	Matrix4();
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	void rotateX(float value);
	void rotateY(float value);
	void rotateZ(float value);
	Matrix4 operator * (Matrix4);
	Vector4 operator * (Vector4);
	Vector4 operator[](int);
};