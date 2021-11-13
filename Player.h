
#include ".\include\raylib.h"
#include "Bullet.h"

class Player
{
public:
    Camera camera;
    Vector3 cameraDirection;
    float cameraSpeed;
    Vector3 dimensions;
    Model model;
    Vector2 mouseDeltaSum;
    float isJumping;
    float jumpAcceleration;

    Player(float _cameraSpeed, Vector3 _dimensions);
    void updateCameraDirection();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    Bullet shoot(Shader shader);
    void jump();
    void updateGravity();
};
