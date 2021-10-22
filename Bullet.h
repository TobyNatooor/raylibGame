#pragma once
#include <vector>
#include ".\include\raylib.h"

class Bullet
{
private:
    Vector3 dime;
    Vector3 dire;
    Color col;
    float bulletSpeed;

public:
    Vector3 pos;

    Bullet(Vector3 dimension, Vector3 position, Vector3 direction, float BulletSpeed, Color color);
    void draw();
    void move();
};