#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() 
{
    register_method("_process", &GDExample::_process);
    //provide class name and datatype of property as Template parameters, then the name of the property, a reference to it and a default value
    register_property<GDExample, float>("amplitude", &GDExample::amplitude, 10.0);

    //register property with getter and setter
    register_property<GDExample, float>("speed", &GDExample::set_speed, &GDExample::get_speed, 1.0); 

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
    // initialize any variables here
    time_passed = 0.0;
    amplitude = 10.0;
    speed = 1.0;
    //time_emit = 0.0;
}

void GDExample::_process(float delta) 
{
    time_passed += delta;

    float yPosition = FunctionLibrary::Wave2D(0,time_passed);
    Vector2 new_position = Vector2(0, amplitude * yPosition);
    set_position(new_position);
}