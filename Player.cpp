#include "./Player.h"

Player::Player(Vector3 _position, Vector3 _dimension, Shader _shader, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight)
    : Entity(_position, _dimension, _shader, _staticBlocks, _movementSpeed, _gravitySpeed, _jumpHeight)
{
    // Camera
    camera = {0};
    camera.position = _position;
    camera.target = Vector3{0.0f, 0.0f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 110.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    isJumping = false;
    isFalling = true;
    mouseDeltaSum = {0.0f, 0.0f};
    movementSpeed = _movementSpeed;
    gravitySpeed = _gravitySpeed;
    jumpHeight = _jumpHeight;
    yAcceleration = _jumpHeight;
    staticBlocks = _staticBlocks;
}

void Player::updateCameraDirection()
{
    camera.position = position;

    Vector2 mouseDelta = GetMouseDelta();
    SetMousePosition((GetScreenWidth() / 2), (GetScreenHeight() / 2));

    mouseDeltaSum.x -= mouseDelta.x / 800;
    mouseDeltaSum.y -= mouseDelta.y / 600;

    if (mouseDeltaSum.y > 1.57f)
        mouseDeltaSum.y = 1.57f;
    if (mouseDeltaSum.y < -1.57f)
        mouseDeltaSum.y = -1.57f;

    direction = Vector3{sinf(mouseDeltaSum.x),
                        tanf(mouseDeltaSum.y),
                        cosf(mouseDeltaSum.x)};

    camera.target = Vector3{camera.position.x + direction.x,
                            camera.position.y + direction.y,
                            camera.position.z + direction.z};
}

void Player::moveForward()
{
    moveXZ(sin(mouseDeltaSum.x),
           cos(mouseDeltaSum.x));
}
void Player::moveBackward()
{
    moveXZ(sin(mouseDeltaSum.x) * -1,
           cos(mouseDeltaSum.x) * -1);
}
void Player::moveLeft()
{
    moveXZ(sin(mouseDeltaSum.x + PI / 2),
           cos(mouseDeltaSum.x + PI / 2));
}
void Player::moveRight()
{
    moveXZ(sin(mouseDeltaSum.x + PI / 2) * -1,
           cos(mouseDeltaSum.x + PI / 2) * -1);
}
