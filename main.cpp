#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include ".\include\raylib.h"

using namespace std;

bool isHitByBullet(Vector3 enemyPos, Vector3 enemyDime, vector<Vector3> bulletPos)
{
    Vector3 enemyCornerOne = {enemyPos.x - enemyDime.x / 2,
                              enemyPos.y - enemyDime.y / 2,
                              enemyPos.z - enemyDime.z / 2};
    Vector3 enemyCornerTwo = {enemyPos.x + enemyDime.x / 2,
                              enemyPos.y + enemyDime.y / 2,
                              enemyPos.z + enemyDime.z / 2};
    for (int i = 0; i < bulletPos.size(); i++)
    {
        if (enemyCornerOne.x < bulletPos[i].x && bulletPos[i].x < enemyCornerTwo.x &&
            enemyCornerOne.y < bulletPos[i].y && bulletPos[i].y < enemyCornerTwo.y &&
            enemyCornerOne.z < bulletPos[i].z && bulletPos[i].z < enemyCornerTwo.z)
        {
            return true;
        }
    }
    return false;
};

// const char* stringToCharArr(string str)
// {
//     int charLength = str.length();
//     char charReturn[charLength];
//     for (int i = 0; i < charLength; i++) {
//         charReturn[i] = str[i];
//     }

// };

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "");

    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    vector<Vector3> bulletDirection = {};
    vector<Vector3> bulletPosition = {};
    Vector3 bulletDimension = {0.3f, 0.3f, 0.3f};
    float bulletSpeed = 0.3f;

    vector<Vector3> enemyPosition = {{-16.0f, 2.5f, 0.0f}, {-16.0f, 8.5f, 0.0f}};
    vector<Vector3> enemyDimension = {{3.0f, 3.0f, 3.0f}, {6.0f, 6.0f, 6.0f}};
    Color enemyColor = GREEN;

    Vector2 mouseCoords = {0.0f, 0.0f};
    int num = 0;
    float cameraSpeed = 0.1f;

    SetCameraMode(camera, CAMERA_CUSTOM);

    //ToggleFullscreen();

    HideCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector3 cameraDirection = {camera.target.x - camera.position.x,
                                   camera.target.y - camera.position.y,
                                   camera.target.z - camera.position.z};

        BeginMode3D(camera);

        // Draws walls and ground
        DrawPlane(Vector3{0.0f, 0.0f, 0.0f}, Vector2{32.0f, 32.0f}, LIGHTGRAY);

        // Draws bullets
        for (int i = 0; i < bulletPosition.size(); i++)
        {
            DrawCube(bulletPosition[i], bulletDimension.x, bulletDimension.y, bulletDimension.z, BLACK);
            bulletPosition[i].x += bulletDirection[i].x * bulletSpeed;
            bulletPosition[i].y += bulletDirection[i].y * bulletSpeed;
            bulletPosition[i].z += bulletDirection[i].z * bulletSpeed;
        };

        // Draws enemies
        for (int i = 0; i < enemyPosition.size(); i++)
        {
            if (isHitByBullet(enemyPosition[i], enemyDimension[i], bulletPosition))
                DrawCube(enemyPosition[i], enemyDimension[i].x, enemyDimension[i].y, enemyDimension[i].z, RED);
            else
                DrawCube(enemyPosition[i], enemyDimension[i].x, enemyDimension[i].y, enemyDimension[i].z, enemyColor);
        };

        EndMode3D();

        // Converts string 'displayString' to char[] to displays it ingame
        string displayString = "[" +
                               to_string(num) + "," +
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
                               to_string(camera.up.x) + "," +
                               to_string(camera.up.y) + "," +
                               to_string(camera.up.z) + "]," +
                               "";
        char tab2[1024];
        strcpy(tab2, displayString.c_str());

        DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 220, 70, BLUE);
        DrawText(tab2, 20, 20, 10, BLACK);

        EndDrawing();

        // Shooting
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bulletPosition.push_back({camera.position.x, camera.position.y, camera.position.z});
            bulletDirection.push_back(cameraDirection);
        };
        // Jumping
        if (IsKeyDown(KEY_SPACE))
        {
            // cout << "test" << endl;
            camera.position.y += 5.5f;
            camera.target.y += 5.5f;
            // float acceleration = 0.5f;
            // while (2.0f < camera.position.x)
            // {
            //     camera.position.x += acceleration;
            //     acceleration -= 0.1f;
            // }
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
            camera.position.x += (cameraDirection.x + 1) * cameraSpeed;
            camera.position.z += (cameraDirection.z + 1) * cameraSpeed;
        }
        // Right
        if (IsKeyDown(KEY_D))
        {
            camera.position.x += (cameraDirection.x + 1) * cameraSpeed;
            camera.position.z += (cameraDirection.z - 1) * cameraSpeed;
        }

        // Moving mouse moves camera target/direction
        // -: left and up, +: right and down
        Vector2 mouseDelta = GetMouseDelta();
        SetMousePosition((GetScreenWidth() / 2), (GetScreenHeight() / 2));

        mouseCoords.x -= mouseDelta.x / 800;
        mouseCoords.y -= mouseDelta.y / 400;

        cameraDirection.x = cos(-mouseCoords.x);
        cameraDirection.y = tan(mouseCoords.y);
        cameraDirection.z = sin(-mouseCoords.x);

        camera.target.x = camera.position.x + cameraDirection.x;
        camera.target.y = camera.position.y + cameraDirection.y;
        camera.target.z = camera.position.z + cameraDirection.z;

        // Prints camera target coordinates when x is pressed
        if (IsKeyDown(KEY_X))
        {
            // cout << displayString << endl;
            cout << to_string(mouseDelta.x) + "   " + to_string(mouseDelta.y) << endl;
            num += 1;
        }
    }

    CloseWindow();

    return 0;
}
