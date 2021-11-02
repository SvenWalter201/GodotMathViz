#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() 
{
	register_method("_init", &GDExample::_init);
	register_method("_ready", &GDExample::_ready);
    register_method("_process", &GDExample::_process);
	register_method("_set_function", &GDExample::_set_function);

    register_property<GDExample, float>("amplitude", &GDExample::amplitude, 0.3f);
    register_property<GDExample, int>("resolution", &GDExample::resolution, 100);
    register_property<GDExample, float>("cube_size Multiplier", &GDExample::cubeSize, 0.9f);
    register_property<GDExample, int>("function", &GDExample::function, 0,
        GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Wave, DoubleWave, TrippleWave, Ripple, Sphere, Torus");

    register_property<GDExample, float>("speed", &GDExample::set_speed, &GDExample::get_speed, 1.0f); 
}

GDExample::GDExample() 
{
}

GDExample::~GDExample() 
{
    for (size_t i = 0; i < nodes.size(); i++)
    {
        nodes[i]->queue_free();
    }
}

void GDExample::_init() 
{
    time_passed = 0.0f;
    amplitude = 0.2f;
    speed = 1.0f;
    resolution = 100;
    cubeSize = 1.0f;
    function = 0;

}


void GDExample::_ready()
{
	function_selection = (OptionButton*)get_node("../CanvasLayer/FunctionSelection");
	function_selection->connect("item_selected", this, "_set_function");

	Ref<Material> Params = godot::ResourceLoader::get_singleton()->load("res://colored_space_mat.tres");
	float step = 2.0f / resolution;
	Vector3 scale = Vector3::ONE * step * cubeSize;
	nodes = std::vector<CSGBox*>(resolution * resolution);

	for (size_t i = 0, x = 0, z = 0; i < nodes.size(); i++, x++)
	{
		if (x == resolution)
		{
			x = 0;
			z += 1;
		}
		CSGBox* s = CSGBox::_new();
		s->set_material(Params);
		s->set_width(scale.x);
		s->set_height(scale.y);
		s->set_depth(scale.z);

		//s->set_scale(scale);
		add_child(s);
		nodes[i] = s;
	}
}


void GDExample::_process(float delta) 
{
    FunctionLibrary::Function3D fun = FunctionLibrary::GetFunction3D(function);

    time_passed += delta * speed;

    float step = 2.0f / (float)resolution;
    float v = 0.5f * step - 1;
    
    for (size_t i = 0, x = 0, z = 0; i < nodes.size(); i++, x++)
    {
        if (x == resolution)
        {
            x = 0;
            z += 1;
            v = (z + 0.5f) * step - 1.0f;
        }

        float u = (x + 0.5f) * step - 1.0f;
        Vector3 p = fun(u, v, time_passed);
        Transform t = nodes[i]->get_global_transform();  
        t.set_origin(p);
        nodes[i]->set_global_transform(t);
    }
}

void GDExample::_set_function(int index)
{
	function = index;
}
