#pragma once
#include ".\include\raylib.h"
#include <vector>
#include "Bullet.h"

class Enemy
{
private:
    Vector3 position;
    Vector3 dimension;
    Material material;

public:
    Model model;
    Color color;

    Enemy(Vector3 _position, Vector3 _dimension, Color _color, Shader shader);
    void draw();
    void drawHit();
    bool isHitByBullets(std::vector<Bullet> bullets);
};
