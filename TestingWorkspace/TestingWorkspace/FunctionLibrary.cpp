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

float FunctionLibrary::Wave3D(float x, float z, float t)
{
	return sin(PI * (x + z + t));
}

float FunctionLibrary::DoubleWave3D(float x, float z, float t)
{
	float y = sin(PI * (x + 0.5f * t));
	y += 0.5f * sin(2.0f * PI * (z + t));

	return y * (2.0f / 3.0f);
}

float FunctionLibrary::TripleWave3D(float x, float z, float t)
{
	float y = sin(PI * (x + t));
	y += 0.5f * sin(2.0f * PI * (z + t)) * (1.0f / 2.0f);
	y += sin(PI * (x + z + 0.25f * t));

	return y / (1.0f / 2.5f);
}

float FunctionLibrary::Ripple3D(float x, float z, float t)
{
	float d = sqrt(x * x + z * z);
	float y = sin(4.0f * PI * d - t);

	return y / (1.0f + 10.0f * d);
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
	if (index == 0) 
	{
		return Wave3D;
	}
	else if (index == 1) 
	{
		return DoubleWave3D;
	}
	else if (index == 2) 
	{
		return TripleWave3D;
	}
	else
	{
		return Ripple3D;
	}
}
