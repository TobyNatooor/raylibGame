#pragma once
#include ".\include\raylib.h"
#include <vector>
#include "Bullet.h"
#include "Block.h"

class Enemy : public Block
{
private:
public:
    /* using Block::Block; */

    Vector3 position;
    Vector3 dimension;
    Material material;
    Model model;
    Color color;

    Enemy(Vector3 _position, Vector3 _dimension, Color _color, Shader shader);
    void draw();
    void drawHit();
    bool isHitByBullets(std::vector<Bullet> bullets);
};
