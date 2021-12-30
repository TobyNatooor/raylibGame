#pragma once
#include <vector>
#include <raylib.h>
#include "Object.h"
#include "Block.h"
#include <iostream>

using std::vector;

class Entity : public Object
{
public:
    int health;
    int attackPower;

    float yAcceleration;
    float movementSpeed;
    float gravitySpeed;
    float jumpHeight;
    bool isJumping;
    bool isFalling;
    vector<Block> staticBlocks;

    Entity(Vector3 _position, Vector3 _dimension, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight);
    void moveXZ(float xDistance, float zDistance);
    void jump();
    void updateGravity();
    bool isColliding();
    void moveBackIfCollision(Vector3 distance);
};
