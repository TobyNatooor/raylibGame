#include "Object.h"

Object::Object(Vector3 _position, Color _color)
{
    position = _position;
    color = _color;
}

void Object::draw()
{
    try
    {
        DrawModel(model, position, 1.0f, color);
    }
    catch (const std::exception &e)
    {
        throw "model is most likely undefined";
    }
}
