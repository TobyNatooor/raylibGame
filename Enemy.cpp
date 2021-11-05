#include ".\include\raylib.h"
#include ".\include\raymath.h"
#include <vector>
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(Vector3 _position, Vector3 _dimension, Color _color, Shader shader)
{
    position = _position;
    dimension = _dimension;
    color = _color;
    model = LoadModelFromMesh(GenMeshCube(_dimension.x, _dimension.y, _dimension.z));
    model.materials[0].shader = shader;
}

void Enemy::draw()
{
    DrawModel(model, position, 1.0f, color);
}

void Enemy::drawHit()
{
    DrawModel(model, position, 1.0f, RED);
}

bool Enemy::isHitByBullets(std::vector<Bullet> bullets)
{
    Vector3 enemyCornerOne = {position.x - dimension.x / 2,
                              position.y - dimension.y / 2,
                              position.z - dimension.z / 2};
    Vector3 enemyCornerTwo = {position.x + dimension.x / 2,
                              position.y + dimension.y / 2,
                              position.z + dimension.z / 2};

    for (int i = 0; i < bullets.size(); i++)
    {
        if (enemyCornerOne.x < bullets[i].position.x && bullets[i].position.x < enemyCornerTwo.x &&
            enemyCornerOne.y < bullets[i].position.y && bullets[i].position.y < enemyCornerTwo.y &&
            enemyCornerOne.z < bullets[i].position.z && bullets[i].position.z < enemyCornerTwo.z)
        {
            return true;
        }
    }
    return false;
};
