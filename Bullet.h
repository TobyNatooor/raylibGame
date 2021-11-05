#pragma once
#include <vector>
#include ".\include\raylib.h"

class Bullet
{
private:
    Vector3 dimension;
    Color color;
    Vector3 direction;
    float bulletSpeed;

public:
    Vector3 position;
    Model model;

    Bullet(Vector3 _position, Vector3 _dimension, Color _color, Vector3 _direction, float _BulletSpeed, Shader shader);
    void draw();
    void move();
};