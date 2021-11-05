#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include "Enemy.h"
#include ".\include\raylib.h"
#define RAYMATH_IMPLEMENTATION
#include ".\include\raymath.h"
#define RLIGHTS_IMPLEMENTATION
#include ".\include\rlights.h"

using namespace std;

int main(void)
{
    int screenWidth = 1280;
    int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "");

    // Camera
    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};
    camera.target = Vector3{0.0f, 1.8f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    const float cameraSpeed = 0.3f;

    // Shader
    Shader shader = LoadShader("../shaders/base_lighting.vs", "../shaders/lighting.fs");
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    const int ambientLoc = GetShaderLocation(shader, "ambient");
    const float floatValue[4] = {0.1f, 0.1f, 0.1f, 1.0f};
    SetShaderValue(shader, ambientLoc, floatValue, SHADER_UNIFORM_VEC4);

    Light light = CreateLight(LIGHT_POINT, Vector3{0, 4, 0}, Vector3{0, 3, 0}, WHITE, shader);

    // Bullets
    vector<Bullet> bullets = {};

    // Enemies
    Enemy enemyOne = Enemy(Vector3{-16.0f, 2.5f, 0.0f}, Vector3{3.0f, 3.0f, 3.0f}, GREEN, shader);
    Enemy enemyTwo = Enemy(Vector3{-16.0f, 8.5f, 0.0f}, Vector3{6.0f, 6.0f, 6.0f}, GREEN, shader);
    vector<Enemy> enemies = {enemyOne, enemyTwo};

    // Groud
    Model model = LoadModelFromMesh(GenMeshPlane(40.0f, 40.0f, 3, 3));
    model.materials[0].shader = shader;

    // Jumping
    float jumpAcceleration = 1.0f;
    bool isJumping = false;

    Vector2 mouseDeltaSum = {0.0f, 0.0f};
    int coutNumber = 0;

    SetCameraMode(camera, CAMERA_CUSTOM);
    SetTargetFPS(60);
    HideCursor();

    while (!WindowShouldClose())
    {
        UpdateLightValues(shader, light);

        // Update the light shader with the camera view position
        float cameraPos[3] = {camera.position.x, camera.position.y, camera.position.z};
        SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }

        Vector3 cameraDirection = {camera.target.x - camera.position.x,
                                   camera.target.y - camera.position.y,
                                   camera.target.z - camera.position.z};

        // Converts string 'displayString' to char[] to displays it ingame
        string displayString = "[" +
                               //    to_string(coutNumber) + "," +
                               //    to_string(camera.target.x) + "," +
                               //    to_string(camera.target.y) + "," +
                               //    to_string(camera.target.z) + "]," +
                               //    "\n[" +
                               to_string(camera.position.x) + "," +
                               to_string(camera.position.y) + "," +
                               to_string(camera.position.z) + "]," +
                               //    "\n[" +
                               //    to_string(cameraDirection.x) + "," +
                               //    to_string(cameraDirection.y) + "," +
                               //    to_string(cameraDirection.z) + "]," +
                               //    "\n[" +
                               //    to_string(mouseDeltaSum.x) + "," +
                               //    to_string(mouseDeltaSum.y) + "]," +
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

        // Ground
        DrawModel(model, Vector3Zero(), 1.0f, WHITE);

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
            bullets.push_back(Bullet(camera.position, {0.3f, 0.3f, 0.3f}, BLACK, cameraDirection, 0.9f, shader));
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
    for (int i = 0; i < enemies.size(); i++)
        UnloadModel(enemies[i].model);
    for (int i = 0; i < bullets.size(); i++)
        UnloadModel(bullets[i].model);
    UnloadModel(model);
    UnloadShader(shader);
    CloseWindow();

    return 0;
}
