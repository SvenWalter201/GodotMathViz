#pragma once

#include <iostream>
#include <thread>
#include <chrono>

namespace MathViz 
{
	class Plotter 
	{
	public:
		Plotter(float t_amplitude, int t_resolution);
		~Plotter();

		void PlotOnce(float t);
		void PlotAmount(float initialTime, float seconds);
		void PlotContinous(float initialTime);

	public:
		float amplitude = 1;
		int resolution = 10;

	private:
		float Sin(float x, float t);
		const float DELTA = 0.016;
	};
}