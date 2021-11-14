#include "./Player.h"
#include <iostream>

Player::Player(float _cameraSpeed, Vector3 _dimensions, std::vector<Block> _staticBlocks)
{
    // Camera
    camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    cameraSpeed = _cameraSpeed;
    dimensions = _dimensions;
    model = LoadModelFromMesh(GenMeshCube(_dimensions.x, _dimensions.y, _dimensions.z));

    isJumping = false;
    jumpAcceleration = 1.0f;
    mouseDeltaSum = {0.0f, 0.0f};
    staticBlocks = _staticBlocks;
}

void Player::updateCameraDirection()
{
    DrawBoundingBox(GetModelBoundingBox(model), RED);

    cameraDirection = {camera.target.x - camera.position.x,
                       camera.target.y - camera.position.y,
                       camera.target.z - camera.position.z};

    Vector2 mouseDelta = GetMouseDelta();

    SetMousePosition((GetScreenWidth() / 2), (GetScreenHeight() / 2));

    mouseDeltaSum.x -= mouseDelta.x / 800;
    mouseDeltaSum.y -= mouseDelta.y / 600;

    if (mouseDeltaSum.y > 1.57f)
        mouseDeltaSum.y = 1.57f;
    if (mouseDeltaSum.y < -1.57f)
        mouseDeltaSum.y = -1.57f;

    cameraDirection.x = sin(mouseDeltaSum.x);
    cameraDirection.y = tan(mouseDeltaSum.y);
    cameraDirection.z = cos(mouseDeltaSum.x);

    camera.target.x = camera.position.x + cameraDirection.x;
    camera.target.y = camera.position.y + cameraDirection.y;
    camera.target.z = camera.position.z + cameraDirection.z;
}

bool Player::isColliding()
{
    for (int i = 0; i < staticBlocks.size(); i++)
        if (staticBlocks[i].hasCollidedWithBlock(camera.position, dimensions))
            return true;
    return false;
}

void Player::moveBackIfCollision(Vector3 distance)
{
    if (0 != distance.x)
    {
        while (isColliding())
            camera.position.x += distance.x * -0.1f;
    }
    else if (0 != distance.y)
    {
        while (isColliding())
            camera.position.y += distance.y * -0.1f;
    }
    else if (0 != distance.z)
    {
        while (isColliding())
            camera.position.z += distance.z * -0.1f;
    }
}

Bullet Player::shoot(Shader shader)
{
    return Bullet(camera.position, Vector3{0.3f, 0.3f, 0.3f}, BLACK, cameraDirection, 0.3f, shader);
}

void Player::jump()
{
    isJumping = true;
}

void Player::updateGravity()
{
    if (isJumping)
    {
        float distance = 0.2f + jumpAcceleration;
        jumpAcceleration += -0.05f;
        camera.position.y += distance;
        if (isColliding())
        {
            jumpAcceleration = 1.0f;
            isJumping = false;
        }
        moveBackIfCollision(Vector3{0, distance, 0});
    }
}

void Player::moveXZ(float xDistance, float zDistance)
{
    camera.position.x += xDistance;
    moveBackIfCollision(Vector3{xDistance, 0, 0});

    camera.position.z += zDistance;
    moveBackIfCollision(Vector3{0, 0, zDistance});
}

void Player::moveForward()
{
    moveXZ(sin(mouseDeltaSum.x) * cameraSpeed,
           cos(mouseDeltaSum.x) * cameraSpeed);
}
void Player::moveBackward()
{
    moveXZ(sin(mouseDeltaSum.x) * cameraSpeed * -1,
           cos(mouseDeltaSum.x) * cameraSpeed * -1);
}
void Player::moveLeft()
{
    moveXZ(sin(mouseDeltaSum.x + PI / 2) * cameraSpeed,
           cos(mouseDeltaSum.x + PI / 2) * cameraSpeed);
}
void Player::moveRight()
{
    moveXZ(sin(mouseDeltaSum.x + PI / 2) * cameraSpeed * -1,
           cos(mouseDeltaSum.x + PI / 2) * cameraSpeed * -1);
}
