#include <iostream>
#include ".\include\raylib.h"
#include <string>

#define MAX_COLUMNS 20

using namespace std;

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 GoldCube = {5.0f, 0.5f, 5.0f};
    bool gcUp = true;

    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY); // Draw ground
        DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);           // Draw a blue wall
        DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);            // Draw a green wall
        DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);            // Draw a yellow wall

        // Moving cube
        if ( 5.0f < GoldCube.y) gcUp = false;
        if (GoldCube.y < 0.5f) gcUp = true;
        DrawCube(GoldCube, 1.0f, 1.0f, 1.0f, GOLD);
        if (gcUp) GoldCube.y += 0.05f;
        if (!gcUp) GoldCube.y -= 0.05f;

        EndMode3D();

        // DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        // DrawRectangleLines( 10, 10, 220, 70, BLUE);
        string StringCameraCoordinates = to_string(camera.target.x) + " " + to_string(camera.target.y) + " " + to_string(camera.target.z);
        // DrawText(StringCameraCoordinates, 20, 20, 10, BLACK);

        EndDrawing();

        if (IsKeyDown(KEY_X)) cout << StringCameraCoordinates << endl;
    }

    CloseWindow();

    return 0;
}