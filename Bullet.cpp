#include "Bullet.h"

Bullet::Bullet(Vector3 _position, Color _color, Shader _shader, Vector3 _direction, float _BulletSpeed, float _radius)
    : Object(_position, Vector3{0, 0, 0}, _color, _shader)
{
    direction = _direction;
    bulletSpeed = _BulletSpeed;
    radius = _radius;
    model = LoadModelFromMesh(GenMeshSphere(_radius, 5, 15));
    model.materials[0].shader = _shader;
};

void Bullet::move()
{
    position.x += direction.x * bulletSpeed;
    position.y += direction.y * bulletSpeed;
    position.z += direction.z * bulletSpeed;
};
