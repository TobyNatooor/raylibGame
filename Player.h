#pragma once
#include <math.h>
#include <vector>
#include "./include/raylib.h"
#include "Bullet.h"
#include "Block.h"
#include "Entity.h"

using std::vector;

class Player : public Entity
{
public:
    Camera camera;
    Vector3 direction;
    Vector2 mouseDeltaSum;

    Player(Vector3 _position, Vector3 _dimension, Shader _shader, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight);
    void updateCameraDirection();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
};
