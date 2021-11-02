#include "PlotterNode.h"

#include <Ref.hpp>


namespace godot
{
	void PlotterNode::_register_methods()
	{
		register_method("_init", &PlotterNode::_init);
		register_method("_ready", &PlotterNode::_ready);
		register_method("_physics_process", &PlotterNode::_physics_process);
		register_method("_set_function", &PlotterNode::_set_function);

		register_property("resolution", &PlotterNode::resolution, 100);
		register_property<PlotterNode, int>("function", &PlotterNode::function, 0,
			GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Wave, DoubleWave, TrippleWave, Ripple, Sphere, Torus");

		register_property<PlotterNode, float>("speed", &PlotterNode::speed, 1.0f);
	}

	void PlotterNode::_init()
	{
		resolution = 100;
		time_passed = 0.0f;
		speed = 1.0f;
	}

	void PlotterNode::_ready()
	{
		resSquared = resolution * resolution;
		MultiMeshInstance* mm_node = (MultiMeshInstance*)get_node("Plane");
		function_selection = (OptionButton*)get_node("../CanvasLayer/FunctionSelection");
		function_selection->connect("item_selected", this, "_set_function");
		mm = mm_node->get_multimesh();
		//Ref<Mesh> m = mm->get_mesh();
		mm->set_instance_count(resSquared);

		for (size_t i = 0, x = 0, z = 0; i < resSquared; i++, x++)
		{
			if (x == resolution)
			{
				x = 0;
				z += 1;
			}
			Vector3 position(x * 0.01, 0, z * 0.01);
			Transform t(Vector3::ZERO, position);
			mm->set_instance_transform(i, t);
		}
	}

	void PlotterNode::_physics_process(float delta)
	{
		time_passed += delta * speed;
		
		FunctionLibrary::Function3D fun = FunctionLibrary::GetFunction3D(function);

		float step = 2.0f / (float)resolution;
		float v = 0.5f * step - 1;

		for (size_t i = 0, x = 0, z = 0; i < resSquared; i++, x++)
		{
			if (x == resolution)
			{
				x = 0;
				z += 1;
				v = (z + 0.5f) * step - 1.0f;
			}

			float u = (x + 0.5f) * step - 1.0f;
			Vector3 p = fun(u, v, time_passed);
			Transform t(Vector3::ZERO, p);
			mm->set_instance_transform(i, t);
		}
	}

	void PlotterNode::_set_function(int index)
	{
		function = index;
	}

}
