#pragma once

#include <Godot.hpp>
#include "FunctionLibrary.h"
#include <vector>
#include <iostream>
#include <CSGBox.hpp>
#include <Spatial.hpp>

namespace godot {

    class GDExample : public Spatial {
        GODOT_CLASS(GDExample, Spatial)

    private:
        float time_passed;
        //float time_emit;
        float cubeSize;
        float amplitude;
        float speed;
        int resolution;
        float resPerCube;
        int function;
        std::vector<CSGBox*> nodes;
        

    public:
        static void _register_methods();

        GDExample();
        ~GDExample();

        void _init(); // our initializer called by Godot

        void _process(float delta);
    
        inline void set_speed(float p_speed) { speed = p_speed; }

        inline float get_speed() { return speed; }
    };
}