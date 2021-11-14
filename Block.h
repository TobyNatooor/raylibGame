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
    bool hasCollidedWithPoint(Vector3 objPosition);
    bool hasCollidedWithBlock(Vector3 objPosition, Vector3 objDimensions);
    bool hasCollidedWithSphere(Vector3 objPosition, Vector3 objDimensions, Vector3 spherePos, float sphereRadius);
    void draw();
};
