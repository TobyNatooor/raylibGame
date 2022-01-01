#pragma once
#include <raylib.h>
#include <stdexcept>

class Object
{
    
public:
    Vector3 position;
    Model model;
    Color color;

    Object(Vector3 _position, Color _color);
    void draw();
};
