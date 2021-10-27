#include "Plotter.h"

namespace MathViz 
{
	Plotter::Plotter(float t_amplitude, int t_resolution) 
		: amplitude(t_amplitude), resolution(t_resolution)
	{
	}

	Plotter::~Plotter() 
	{

	}

	void Plotter::PlotOnce(float t) 
	{
		std::cout << t << "----";
		for (size_t i = 0; i < resolution; i++)
		{
			float y = Sin(i, t) * amplitude;
			std::cout << "[" << y << "]";
			if (y < resolution - 1) {
				std::cout << ",";
			}
		}
		std::cout << std::endl;
	}

	void Plotter::PlotAmount(float initialTime, float seconds) 
	{
		float finalTime = initialTime + seconds;
		while (initialTime < finalTime) 
		{
			PlotOnce(initialTime);
			initialTime += DELTA;
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(DELTA * 1000)));
		}
	}

	void Plotter::PlotContinous(float initialTime) 
	{

	}

	float Plotter::Sin(float x, float t) 
	{
		return sin(x + t);
	}
}