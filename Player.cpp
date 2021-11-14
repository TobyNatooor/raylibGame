
#include "./Player.h"

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
    float xDistance = sin(mouseDeltaSum.x) * cameraSpeed;
    camera.position.x += xDistance;
    ifCollisionShortenDistance(Vector3{xDistance, 0, 0});

    float zDistance = cos(mouseDeltaSum.x) * cameraSpeed;
    camera.position.z += zDistance;
    ifCollisionShortenDistance(Vector3{0, 0, zDistance});
}

void Player::moveBackward()
{
    float xDistance = sin(mouseDeltaSum.x) * cameraSpeed * -1;
    camera.position.x += xDistance;
    ifCollisionShortenDistance(Vector3{xDistance, 0, 0});

    float zDistance = cos(mouseDeltaSum.x) * cameraSpeed * -1;
    camera.position.z += zDistance;
    ifCollisionShortenDistance(Vector3{0, 0, zDistance});
}
void Player::moveLeft()
{
    float xDistance = sin(mouseDeltaSum.x + PI / 2) * cameraSpeed;
    camera.position.x += xDistance;
    ifCollisionShortenDistance(Vector3{xDistance, 0, 0});

    float zDistance = cos(mouseDeltaSum.x + PI / 2) * cameraSpeed;
    camera.position.z += zDistance;
    ifCollisionShortenDistance(Vector3{0, 0, zDistance});
}
void Player::moveRight()
{
    float xDistance = sin(mouseDeltaSum.x + PI / 2) * cameraSpeed * -1;
    camera.position.x += xDistance;
    ifCollisionShortenDistance(Vector3{xDistance, 0, 0});

    float zDistance = cos(mouseDeltaSum.x + PI / 2) * cameraSpeed * -1;
    camera.position.z += zDistance;
    ifCollisionShortenDistance(Vector3{0, 0, zDistance});
}

void Player::ifCollisionShortenDistance(Vector3 distance)
{
    if (0 != distance.x)
        for (int i = 0; i < staticBlocks.size(); i++)
            while (staticBlocks[i].hasCollidedWithBlock(camera.position, dimensions))
                camera.position.x += distance.x * -0.1f;
    else if (0 != distance.y)
        for (int i = 0; i < staticBlocks.size(); i++)
            while (staticBlocks[i].hasCollidedWithBlock(camera.position, dimensions))
                camera.position.y += distance.y * -0.1f;
    else if (0 != distance.z)
        for (int i = 0; i < staticBlocks.size(); i++)
            while (staticBlocks[i].hasCollidedWithBlock(camera.position, dimensions))
                camera.position.z += distance.z * -0.1f;
}
