#pragma once
#include ".\include\raylib.h"
#include "Bullet.h"
#include <math.h>
#include "Block.h"

class Player
{
public:
    Camera camera;
    Vector3 cameraDirection;
    float cameraSpeed;
    Vector3 dimensions;
    Model model;
    Vector2 mouseDeltaSum;
    bool isJumping;
    float jumpAcceleration;
    std::vector<Block> staticBlocks;

    Player(float _cameraSpeed, Vector3 _dimensions, std::vector<Block> _staticBlocks);
    void updateCameraDirection();
    void moveXZ(float xDistance, float zDistance);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    Bullet shoot(Shader shader);
    void jump();
    void updateGravity();
    bool isColliding();
    void moveBackIfCollision(Vector3 distance);
};
