#include "Enemy.h"

Enemy::Enemy(Vector3 _position, Vector3 _dimension, Color _color, Shader _shader)
    : Block(_position, _dimension, _color, _shader)
{
}

void Enemy::drawHit()
{
    DrawModel(model, position, 1.0f, RED);
}

bool Enemy::isHitByBullets(std::vector<Bullet> bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (Block::hasCollidedWithSphere(bullets[i].position, bullets[i].radius))
            return true;
    }
    return false;
};
