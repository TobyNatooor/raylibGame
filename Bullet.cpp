#include <vector>
#include ".\include\raylib.h"
#include "Bullet.h"

Bullet::Bullet(Vector3 _position, Vector3 _dimension, Color _color, Vector3 _direction, float _BulletSpeed, Shader shader)
{
    position = _position;
    dimension = _dimension;
    direction = _direction;
    color = _color;
    bulletSpeed = _BulletSpeed;
    model = LoadModelFromMesh(GenMeshSphere(0.3f, 5, 15));
    model.materials[0].shader = shader;
};

void Bullet::draw()
{
    DrawModel(model, position, 1.0f, color);
};

void Bullet::move()
{
    position.x += direction.x * bulletSpeed;
    position.y += direction.y * bulletSpeed;
    position.z += direction.z * bulletSpeed;
};
