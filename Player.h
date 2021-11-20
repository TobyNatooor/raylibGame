#pragma once
#include <math.h>
#include <vector>
#include "./include/raylib.h"
#include "Bullet.h"
#include "Block.h"

using std::vector;

class Player : public Block
{
public:
    Camera camera;
    Vector3 direction;
    Vector2 mouseDeltaSum;
    float yAcceleration;
    float movementSpeed;
    float gravitySpeed;
    float jumpHeight;
    bool isJumping;
    bool isFalling;
    vector<Block> staticBlocks;

    Player(Vector3 _position, Vector3 _dimension, Shader _shader, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight);
    void updateCameraDirection();
    void moveXZ(float xDistance, float zDistance);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void jump();
    void updateGravity();
    bool isColliding();
    void moveBackIfCollision(Vector3 distance);
};
