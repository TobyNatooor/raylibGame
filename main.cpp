#include <iostream>
#include <string>
#include <vector>
#include ".\include\raylib.h"

#define MAX_COLUMNS 20

using namespace std;

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "first person shooter");

    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    std::vector<Vector3> bullets = {};
    float bulletSpeed = 0.3f;

    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane(Vector3{0.0f, 0.0f, 0.0f}, Vector2{32.0f, 32.0f}, LIGHTGRAY); // Draw ground
        DrawCube(Vector3{-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);           // Draw a blue wall
        DrawCube(Vector3{16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);            // Draw a green wall
        DrawCube(Vector3{0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);            // Draw a yellow wall

        // bullets
        for (int i = 0; i < bullets.size() ;i += 2) {
            DrawCube(bullets[i], 0.3f, 0.3f, 0.3f, GOLD);
            bullets[i].x += bullets[i + 1].x * bulletSpeed;
            bullets[i].y += bullets[i + 1].y * bulletSpeed;
            bullets[i].z += bullets[i + 1].z * bulletSpeed;
        };
        EndMode3D();

        // DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        // DrawRectangleLines( 10, 10, 220, 70, BLUE);
        // DrawText(StringCameraCoordinates, 20, 20, 10, BLACK);

        EndDrawing();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector3 startPosition = {camera.position.x, camera.position.y, camera.position.z};
            Vector3 bulletDirection = {camera.target.x - camera.position.x, camera.target.y - camera.position.y, camera.target.z - camera.position.z};
            bullets.push_back(startPosition);
            bullets.push_back(bulletDirection);
        };

        // string StringCameraCoordinates = to_string(camera.target.x - camera.position.x) + " " + to_string(camera.target.y - camera.position.y) + " " + to_string(camera.target.z - camera.position.z);
        // if (IsKeyDown(KEY_X)) cout << StringCameraCoordinates /* << endl << xxx */ << endl;
    }

    CloseWindow();

    return 0;
}