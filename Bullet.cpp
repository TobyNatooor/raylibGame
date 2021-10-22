#include <vector>
#include ".\include\raylib.h"
#include "Bullet.h"

Bullet::Bullet(Vector3 dimension, Vector3 position, Vector3 direction, float BulletSpeed, Color color)
{
    pos = position;
    dime = dimension;
    dire = direction;
    col = color;
    bulletSpeed = BulletSpeed;
};

void Bullet::draw()
{
    DrawCube(pos, dime.x, dime.y, dime.z, col);
};

void Bullet::move()
{
    pos.x += dire.x * bulletSpeed;
    pos.y += dire.y * bulletSpeed;
    pos.z += dire.z * bulletSpeed;
};
