#pragma once
#include ".\include\raylib.h"

class Block
{
private:
    Vector3 dimension;
    Color color;
    Vector3 direction;

public:
    Vector3 position;
    Model model;
    
    Block(Vector3 _position, Vector3 _dimension, Color _color, Shader shader);
    bool hasCollidedWith(Vector3 objPosition);
    void draw();
};
