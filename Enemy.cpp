#include ".\include\raylib.h"
#include <vector>
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(Vector3 _position, Vector3 _dimension, Color _color)
{
    pos = _position;
    dimension = _dimension;
    color = _color;
}

void Enemy::draw()
{
    DrawCube(pos, dimension.x, dimension.y, dimension.z, color);
}

void Enemy::drawHit()
{
    DrawCube(pos, dimension.x, dimension.y, dimension.z, RED);
}

bool Enemy::isHitByBullets(std::vector<Bullet> bullets)
{
    Vector3 enemyCornerOne = {pos.x - dimension.x / 2,
                              pos.y - dimension.y / 2,
                              pos.z - dimension.z / 2};
    Vector3 enemyCornerTwo = {pos.x + dimension.x / 2,
                              pos.y + dimension.y / 2,
                              pos.z + dimension.z / 2};

    for (int i = 0; i < bullets.size(); i++)
    {
        if (enemyCornerOne.x < bullets[i].pos.x && bullets[i].pos.x < enemyCornerTwo.x &&
            enemyCornerOne.y < bullets[i].pos.y && bullets[i].pos.y < enemyCornerTwo.y &&
            enemyCornerOne.z < bullets[i].pos.z && bullets[i].pos.z < enemyCornerTwo.z)
        {
            return true;
        }
    }
    return false;
};
