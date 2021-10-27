#pragma once



static class FunctionLibrary
{
public:
	static const float PI;
	typedef float (*Function2D) (float x, float t);
	typedef float (*Function3D) (float x, float z, float t);

public:
	static float Wave2D(float x, float t);
	static float MultiWave2D(float x, float t);
	static float Ripple2D(float x, float t);

	static float Wave3D(float x, float z, float t);
	static float DoubleWave3D(float x, float z, float t);
	static float TripleWave3D(float x, float z, float t);
	static float Ripple3D(float x, float z, float t);


	static Function2D GetFunction2D(int index);
	static Function3D GetFunction3D(int index);
};

