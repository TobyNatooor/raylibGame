#include "./Player.h"

Player::Player(Vector3 _position, Vector3 _dimension, Shader _shader, vector<Block> _staticBlocks, float _movementSpeed, float _gravitySpeed, float _jumpHeight)
    : Block(_position, _dimension, RED, _shader)
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

bool Player::isColliding()
{
    for (Block &staticBlock : staticBlocks)
        if (staticBlock.hasCollidedWithBlock(camera.position, dimension))
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

void Player::jump()
{
    if (!isJumping)
        yAcceleration = jumpHeight;
    isJumping = true;
}

void Player::updateGravity()
{
    // Detects falling
    camera.position.y -= 0.1f;
    if (isColliding())
        isFalling = false;
    else
        isFalling = true;
    camera.position.y += 0.1f;
    // Falling gravity
    if (isJumping || isFalling)
    {
        float distance;
        if (isJumping)
            distance = -yAcceleration + jumpHeight * 2;
        else if (isFalling)
            distance = -yAcceleration + jumpHeight;

        camera.position.y += distance;
        yAcceleration += gravitySpeed;
        if (isColliding())
        {
            moveBackIfCollision(Vector3{0, distance, 0});
            yAcceleration = jumpHeight;
            isJumping = false;
        }
    }
}

void Player::moveXZ(float xDistance, float zDistance)
{
    camera.position.x += xDistance * movementSpeed;
    moveBackIfCollision(Vector3{xDistance, 0, 0});

    camera.position.z += zDistance * movementSpeed;
    moveBackIfCollision(Vector3{0, 0, zDistance});
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
