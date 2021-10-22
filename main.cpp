#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include ".\include\raylib.h"
#include "Enemy.h"

using namespace std;

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "");

    // Camera
    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    const float cameraSpeed = 0.1f;

    // Bullets
    vector<Bullet> bullets = {};

    // Enemies
    Enemy enemyOne = Enemy(Vector3{-16.0f, 2.5f, 0.0f}, Vector3{3.0f, 3.0f, 3.0f}, GREEN);
    Enemy enemyTwo = Enemy(Vector3{-16.0f, 8.5f, 0.0f}, Vector3{6.0f, 6.0f, 6.0f}, GREEN);
    vector<Enemy> enemies = {enemyOne, enemyTwo};

    // Jumping
    float jumpAcceleration = 1.0f;
    bool isJumping = false;

    Vector2 mouseDeltaSum = {0.0f, 0.0f};
    int coutNumber = 0;

    SetCameraMode(camera, CAMERA_CUSTOM);
    SetTargetFPS(60);
    //SetExitKey(KEY_DELETE);
    HideCursor();

    while (!WindowShouldClose())
    {
        Vector3 cameraDirection = {camera.target.x - camera.position.x,
                                   camera.target.y - camera.position.y,
                                   camera.target.z - camera.position.z};

        // Converts string 'displayString' to char[] to displays it ingame
        string displayString = "[" +
                               to_string(coutNumber) + "," +
                               to_string(camera.target.x) + "," +
                               to_string(camera.target.y) + "," +
                               to_string(camera.target.z) + "]," +
                               "\n[" +
                               to_string(camera.position.x) + "," +
                               to_string(camera.position.y) + "," +
                               to_string(camera.position.z) + "]," +
                               "\n[" +
                               to_string(cameraDirection.x) + "," +
                               to_string(cameraDirection.y) + "," +
                               to_string(cameraDirection.z) + "]," +
                               "\n[" +
                               to_string(mouseDeltaSum.x) + "," +
                               to_string(mouseDeltaSum.y) + "]," +
                               //    "\n[" +
                               //    to_string(camera.up.x) + "," +
                               //    to_string(camera.up.y) + "," +
                               //    to_string(camera.up.z) + "]," +
                               "";
        char displayChar[1024];
        strcpy(displayChar, displayString.c_str());

        UpdateCamera(&camera);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        // Draws walls and ground
        DrawPlane(Vector3{0.0f, 0.0f, 0.0f}, Vector2{100.0f, 100.0f}, LIGHTGRAY);

        // Draws bullets
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].move();
            bullets[i].draw();
        };

        // Draws enemies
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].isHitByBullets(bullets))
                enemies[i].drawHit();
            else
                enemies[i].draw();
        };

        EndMode3D();

        DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 220, 70, BLUE);
        DrawText(displayChar, 20, 20, 10, BLACK);

        EndDrawing();

        // Shooting
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bullets.push_back(Bullet({0.3f, 0.3f, 0.3f}, camera.position, cameraDirection, 1.0f, BLACK));
        };
        // Jumping
        if (IsKeyDown(KEY_SPACE))
        {
            isJumping = true;
        };
        if (isJumping)
        {
            camera.position.y += 0.05f + jumpAcceleration;
            jumpAcceleration += -0.05f;
            if (camera.position.y < 2.0f)
            {
                jumpAcceleration = 1.0f;
                camera.position.y = 2.0f;
                isJumping = false;
            };
        };
        // Forward
        if (IsKeyDown(KEY_W))
        {
            camera.position.x += cameraDirection.x * cameraSpeed;
            camera.position.z += cameraDirection.z * cameraSpeed;
        }
        // Backward
        if (IsKeyDown(KEY_S))
        {
            camera.position.x += -cameraDirection.x * cameraSpeed;
            camera.position.z += -cameraDirection.z * cameraSpeed;
        }
        // Left
        if (IsKeyDown(KEY_A))
        {
            camera.position.x += (asin(cameraDirection.z) * 0.64f - 0) * cameraSpeed;
            camera.position.z += (acos(cameraDirection.x) * 0.64f - 1) * cameraSpeed;
        }
        // Right
        if (IsKeyDown(KEY_D))
        {
            camera.position.x += (acos(cameraDirection.z) * 0.64f - 1) * cameraSpeed;
            camera.position.z += (asin(cameraDirection.x) * 0.64f - 0) * cameraSpeed;
        }

        // Moving mouse moves camera target/direction
        // -: left and up, +: right and down
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

        // Prints camera target coordinates when x is pressed
        if (IsKeyDown(KEY_X))
        {
            // cout << displayString << endl;
            cout << to_string(mouseDeltaSum.x) + "   " + to_string(mouseDeltaSum.y) << endl;
            coutNumber += 1;
        }
    }

    CloseWindow();

    return 0;
}
