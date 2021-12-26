#include "./Object.h"

Object::Object(Vector3 _position, Vector3 _dimension, Color _color)
{
    dimension = _dimension;
    position = _position;
    color = _color;
}

void Object::draw()
{
    DrawModel(model, position, 1.0f, color);
}
