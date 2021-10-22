#pragma once
#include ".\include\raylib.h"
#include <vector>
#include "Bullet.h"

class Enemy
{
private:
    Vector3 pos;
    Vector3 dimension;

public:
    Color color;

    Enemy(Vector3 _position, Vector3 _dimension, Color _color);
    void draw();
    void drawHit();
    bool isHitByBullets(std::vector<Bullet> bullets);
};
