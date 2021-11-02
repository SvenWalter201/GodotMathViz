#pragma once

#include <Godot.hpp>
#include <Spatial.hpp>
#include <ResourceLoader.hpp>
#include <vector>
#include <MultiMeshInstance.hpp>
#include <MultiMesh.hpp>
#include "FunctionLibrary.h"
#include <OptionButton.hpp>

namespace godot
{
	class PlotterNode : public Spatial
	{
		GODOT_CLASS(PlotterNode, Spatial);
	public:
		int resolution;
		int function;
		float speed;
		Ref<MultiMesh> mm;

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _physics_process(float delta);
		void _set_function(int index);

	private:
		int resSquared;
		float time_passed;
		OptionButton* function_selection;
	};
}
