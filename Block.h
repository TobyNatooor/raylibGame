#pragma once
#include <raylib.h>
#include "Object.h"

class Block : public Object
{
public:
    Vector3 dimension;

    Block(Vector3 _position, Vector3 _dimension, Color _color, Shader _shader);
    bool hasCollidedWithPoint(Vector3 objPosition);
    bool hasCollidedWithBlock(Vector3 objPosition, Vector3 objDimensions);
    bool hasCollidedWithSphere(Vector3 spherePos, float sphereRadius);
};
