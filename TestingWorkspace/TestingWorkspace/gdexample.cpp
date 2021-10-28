#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() 
{
    register_method("_process", &GDExample::_process);
    //provide class name and datatype of property as Template parameters, then the name of the property, a reference to it and a default value
    register_property<GDExample, float>("amplitude", &GDExample::amplitude, 0.3f);
    register_property<GDExample, int>("resolution", &GDExample::resolution, 100);
    register_property<GDExample, float>("cube_size", &GDExample::cubeSize, 0.9f);
    register_property<GDExample, int>("function", &GDExample::function, 0,
        GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Wave, DoubleWave, TrippleWave, Ripple");

    //register property with getter and setter
    register_property<GDExample, float>("speed", &GDExample::set_speed, &GDExample::get_speed, 1.0f); 

    //register_signal<GDExample>((char*)"position_changed", "node", GODOT_VARIANT_TYPE_OBJECT, "new_pos", GODOT_VARIANT_TYPE_VECTOR2);
}

GDExample::GDExample() 
{
}

GDExample::~GDExample() 
{
    // add your cleanup here
}

void GDExample::_init() 
{
    time_passed = 0.0f;
    amplitude = 0.2f;
    speed = 1.0f;
    resolution = 100;
    cubeSize = 1.0f;
    function = 0;

    float spacePerCube = 2 / (float)resolution;
    float scaledCubeSize = spacePerCube * cubeSize;
    resPerCube = (2 * 3.14) / resolution;
    nodes = std::vector<CSGBox*>(resolution * resolution);
    for (size_t i = 0, x = 0, z = 0; i < nodes.size(); i++, x++)
    {
        if (x == resolution)
        {
            x = 0;
            z += 1;
        }
        CSGBox* s = CSGBox::_new();

        s->set_scale(Vector3(scaledCubeSize, scaledCubeSize, scaledCubeSize));

        add_child(s);
        s->set_translation(Vector3(
            (x + 0.5f) * spacePerCube - 1, 
            0, 
            (z + 0.5f) * spacePerCube - 1.0f));
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
        float y = fun( u, v, time_passed) * amplitude;
        CSGBox* n = nodes[i];
        Vector3 t = n->get_translation();
        t.y = y;
        nodes[i]->set_translation(t);
    }
    
}