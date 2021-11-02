#pragma once

#include <Vector3.hpp>

using namespace godot;

static class FunctionLibrary
{
public:
	static const float PI;
	typedef float (*Function2D) (float x, float t);
	typedef Vector3 (*Function3D) (float x, float z, float t);

public:
	static float Wave2D(float x, float t);
	static float MultiWave2D(float x, float t);
	static float Ripple2D(float x, float t);

	static Vector3 Wave3D(float x, float z, float t);
	static Vector3 DoubleWave3D(float x, float z, float t);
	static Vector3 TripleWave3D(float x, float z, float t);
	static Vector3 Ripple3D(float x, float z, float t);
	static Vector3 Sphere(float x, float z, float t);
	static Vector3 Torus(float x, float z, float t);

	static Function2D GetFunction2D(int index);
	static Function3D GetFunction3D(int index);
};

