#pragma once
#include "./include/raylib.h"
#include <vector>
#include "Bullet.h"
#include "Block.h"

using std::vector;

class Enemy : public Block
{
public:
    Enemy(Vector3 _position, Vector3 _dimension, Color _color, Shader _shader);
    void drawHit();
    bool isHitByBullets(vector<Bullet> bullets);
};
