
#include "./Player.h"
#include <math.h>

Player::Player(float _cameraSpeed, Vector3 _dimensions)
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
}

void Player::updateCameraDirection()
{
    cameraDirection = {camera.target.x - camera.position.x,
                       camera.target.y - camera.position.y,
                       camera.target.z - camera.position.z};

    Vector2 mouseDelta = GetMouseDelta();

    SetMousePosition((GetScreenWidth() / 2), (GetScreenHeight() / 2));

    mouseDeltaSum.x -= mouseDelta.x / 800;
    mouseDeltaSum.y -= mouseDelta.y / 600;

    cameraDirection.x = cos(-mouseDeltaSum.x);
    cameraDirection.y = tan(mouseDeltaSum.y);
    cameraDirection.z = sin(-mouseDeltaSum.x);

    camera.target.x = camera.position.x + cameraDirection.x;
    camera.target.y = camera.position.y + cameraDirection.y;
    camera.target.z = camera.position.z + cameraDirection.z;
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
        camera.position.y += 0.05f + jumpAcceleration;
        jumpAcceleration += -0.05f;
        if (camera.position.y < dimensions.y)
        {
            jumpAcceleration = 1.0f;
            camera.position.y = dimensions.y;
            isJumping = false;
        };
    }
}

void Player::moveForward()
{
    camera.position.x += cameraDirection.x * cameraSpeed;
    // while (block.hasCollidedWith(camera.position))
    //     camera.position.x -= cameraDirection.x * cameraSpeed * 0.1;

    camera.position.z += cameraDirection.z * cameraSpeed;
    // while (block.hasCollidedWith(camera.position))
    //     camera.position.z -= cameraDirection.z * cameraSpeed * 0.1;
}

void Player::moveBackward()
{
    camera.position.x += -cameraDirection.x * cameraSpeed;
    camera.position.z += -cameraDirection.z * cameraSpeed;
}
void Player::moveLeft()
{
    camera.position.x += (asin(cameraDirection.z) * 0.64f - 0) * cameraSpeed;
    camera.position.z += (acos(cameraDirection.x) * 0.64f - 1) * cameraSpeed;
}
void Player::moveRight()
{
    camera.position.x += (acos(cameraDirection.z) * 0.64f - 1) * cameraSpeed;
    camera.position.z += (asin(cameraDirection.x) * 0.64f - 0) * cameraSpeed;
}