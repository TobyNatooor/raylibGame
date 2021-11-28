#include "Entity.h"

Entity::Entity(Vector3 _position, Vector3 _dimension, Shader _shader, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight)
    : Object(_position, _dimension, RED, _shader)
{

}

bool Entity::isColliding()
{
    for (Block &staticBlock : staticBlocks)
        if (staticBlock.hasCollidedWithBlock(position, dimension))
            return true;
    return false;
}

void Entity::moveBackIfCollision(Vector3 distance)
{
    if (0 != distance.x)
    {
        while (isColliding())
            position.x += distance.x * -0.1f;
    }
    else if (0 != distance.y)
    {
        while (isColliding())
            position.y += distance.y * -0.1f;
    }
    else if (0 != distance.z)
    {
        while (isColliding())
            position.z += distance.z * -0.1f;
    }
}

void Entity::jump()
{
    if (!isJumping)
        yAcceleration = jumpHeight;
    isJumping = true;
}

void Entity::updateGravity()
{
    // Detects falling
    position.y -= 0.1f;
    if (isColliding())
        isFalling = false;
    else
        isFalling = true;
    position.y += 0.1f;
    // Falling gravity
    if (isJumping || isFalling)
    {
        float distance;
        if (isJumping)
            distance = -yAcceleration + jumpHeight * 2;
        else if (isFalling)
            distance = -yAcceleration + jumpHeight;

        position.y += distance;
        yAcceleration += gravitySpeed;
        if (isColliding())
        {
            moveBackIfCollision(Vector3{0, distance, 0});
            yAcceleration = jumpHeight;
            isJumping = false;
        }
    }
}

void Entity::moveXZ(float xDistance, float zDistance)
{
    position.x += xDistance * movementSpeed;
    moveBackIfCollision(Vector3{xDistance, 0, 0});

    position.z += zDistance * movementSpeed;
    moveBackIfCollision(Vector3{0, 0, zDistance});
}
