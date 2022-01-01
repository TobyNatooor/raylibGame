#pragma once
#include <math.h>
#include <vector>
#include <raylib.h>
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
    Vector2 lastMouseDelta;

    Player(Vector3 _position = Vector3{0.0f, 0.0f, 0.0f},
           Vector3 _dimension = Vector3{1.0f, 2.0f, 1.0f},
           vector<Block> _staticBlocks = {}, float _movementSpeed = 0.15f,
           float _gravitySpeed = 0.02f, float _jumpHeight = 0.6f);
    void updateCameraDirection();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
};
