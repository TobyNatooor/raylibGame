#pragma once
#include "./include/raylib.h"
#include "./Object.h"

class Bullet : public Object
{
public:
    Vector3 direction;
    float bulletSpeed;
    float radius;

    Bullet(Vector3 _position, Color _color, Shader _shader, Vector3 _direction, float _BulletSpeed, float _radius);
    void move();
};