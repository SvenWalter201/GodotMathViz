#include "FunctionLibrary.h"

#include<iostream>

const float FunctionLibrary::PI = 3.14159265358979323846f;

float FunctionLibrary::Wave2D(float x, float t)
{
	return sin(PI * (x + t));
}

float FunctionLibrary::MultiWave2D(float x, float t)
{
	float y = sin(PI * (x + t));
	y += 0.5f * sin(2.0f * PI * (x + t)) *(1.0f /  2.0f);

	return y / (2.0f / 3.0f);
}

float FunctionLibrary::Ripple2D(float x, float t)
{
	float d = abs(x);
	float y = sin(4.0f * PI * d - t);

	return y / (1.0f + 10.0f * d);
}

Vector3 FunctionLibrary::Wave3D(float x, float z, float t)
{
	Vector3 p;
	p.x = x;
	p.y = sin(PI * (x + z + t));
	p.z = z;
	return p;
}

Vector3 FunctionLibrary::DoubleWave3D(float x, float z, float t)
{
	Vector3 p;
	p.x = x;
	float y = sin(PI * (x + 0.5f * t));
	y += 0.5f * sin(2.0f * PI * (z + t));
	y *= (2.0f / 3.0f);
	p.y = y;
	p.z = z;
	return p;
}

Vector3 FunctionLibrary::TripleWave3D(float x, float z, float t)
{
	Vector3 p;
	p.x = x;
	p.y = sin(PI * (x + 0.5f * t));
	p.y += 0.5f * sin(2.0f * PI * (z + t));
	p.y += sin(PI * (x + z + 0.25f * t));
	p.y *= 1.0f / 2.5f;
	p.z = z;
	return p;
}

Vector3 FunctionLibrary::Ripple3D(float x, float z, float t)
{
	float d = sqrt(x * x + z * z);
	Vector3 p;
	p.x = x;
	p.y = sin(PI * (4.0f * d - t));
	p.y /= 1.0f + 10.0f * d;
	p.z = z;
	return p;
}

Vector3 FunctionLibrary::Sphere(float x, float z, float t) {
	float r = 0.9f + 0.1f * sin(PI * (6.0f *x + 4.0f * z + t));
	float s = r * cos(0.5f * PI * z);
	Vector3 p;
	p.x = s * sin(PI * x);
	p.y = r * sin(0.5f * PI * z);
	p.z = s * cos(PI * x);
	return p;
}

Vector3 FunctionLibrary::Torus(float x, float z, float t) {
	float r1 = 0.7f + 0.1f * sin(PI * (6.0f * x + 0.5f * t));
	float r2 = 0.15f + 0.05f * sin(PI * (8.0f * x + 4.0f * z + 2.0f * t));
	float s = r1 + r2 * cos(PI * z);
	Vector3 p;
	p.x = s * sin(PI * x);
	p.y = r2 * sin(PI * z);
	p.z = s * cos(PI * x);
	return p;
}

FunctionLibrary::Function2D FunctionLibrary::GetFunction2D(int index)
{

	if (index == 0) 
	{
		return Wave2D;
	}
	else if (index == 1) 
	{
		return MultiWave2D;
	}
	else 
	{
		return Ripple2D;
	}
}

FunctionLibrary::Function3D FunctionLibrary::GetFunction3D(int index)
{
	switch (index)
	{
		case 0: return Wave3D;
		case 1: return DoubleWave3D;
		case 2: return TripleWave3D;
		case 3: return Ripple3D;
		case 4: return Sphere;
		case 5: return Torus;
		default: return Wave3D;
	}
}


