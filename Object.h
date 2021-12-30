#pragma once
#include <raylib.h>

class Object
{
    
public:
    Vector3 dimension;
    Vector3 position;
    Color color;
    Model model;

    Object(Vector3 _position, Vector3 _dimension, Color _color);
    void draw();
};
