#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include "raylib.h"
#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"
#include "Player.h"
#include "Enemy.h"
#include "Block.h"

using namespace std;

// void displayDataWindow(Player player)
// {
//     // Converts string 'displayString' to char[] to displays it ingame
//     string displayString = "[" +
//                            to_string(GetFPS()) + "\n" +
//                            //    to_string(camera.target.x) + "," +
//                            //    to_string(camera.target.y) + "," +
//                            //    to_string(camera.target.z) + "]," +
//                            //    "\n[" +
//                            to_string(player.camera.position.x) + "," +
//                            to_string(player.camera.position.y) + "," +
//                            to_string(player.camera.position.z) + "]," +
//                            //    "\n[" +
//                            //    to_string(player.direction.x) + "," +
//                            //    to_string(player.direction.y) + "," +
//                            //    to_string(player.direction.z) + "]," +
//                            //   "\n[" +
//                            //   to_string(player.mouseDeltaSum.x) + "," +
//                            //   to_string(player.mouseDeltaSum.y) + "]," +
//                            //    "\n" + to_string(player.isFalling) +
//                            "";
//     char displayChar[1024];
//     strcpy_s(displayChar, displayString.c_str());

//     DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
//     DrawRectangleLines(10, 10, 220, 70, BLUE);
//     DrawText(displayChar, 20, 20, 10, BLACK);
// }

int main(void)
{
    int screenWidth = 1280;
    int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "C++ Game");

    // Shader
    Shader shader = LoadShader("./shaders/base_lighting.vs", "./shaders/lighting.fs");
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

    // Blocks
    Block ground = Block(Vector3{0, -5, 0}, Vector3{30.0f, 3.0f, 30.0f}, GREEN, shader);
    Block blockOne = Block(Vector3{-5.0f, 2.0f, -5.0f}, Vector3{3.0f, 3.0f, 3.0f}, GRAY, shader);
    Block blockTwo = Block(Vector3{-7.0f, 2.0f, -7.0f}, Vector3{3.0f, 6.0f, 3.0f}, RED, shader);
    vector<Block> staticBlocks = {ground, blockOne, blockTwo};

    // Player
    Player player = Player(Vector3{4.0f, 2.0f, 4.0f}, Vector3{1.0f, 2.0f, 1.0f}, shader, staticBlocks, 0.2f, 0.8f);

    SetCameraMode(player.camera, CAMERA_CUSTOM);
    SetTargetFPS(60);
    HideCursor();

    while (!WindowShouldClose())
    {
        UpdateLightValues(shader, light);
        player.updateCameraDirection();

        float cameraPos[3] = {player.camera.position.x, player.camera.position.y, player.camera.position.z};
        SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }

        UpdateCamera(&player.camera);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(player.camera);

        // Draw bullets
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].move();
            bullets[i].draw();
        };

        // Draw enemies
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].isHitByBullets(bullets))
                enemies[i].drawHit();
            else
                enemies[i].draw();
        };

        // Draw blocks
        for (int i = 0; i < staticBlocks.size(); i++)
        {
            staticBlocks[i].draw();
        };

        EndMode3D();

        // displayDataWindow(player);

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Bullet bullet = Bullet(player.camera.position, BLACK, shader, player.direction, 0.3f, 0.3f);
            bullets.push_back(bullet);
        }
        if (IsKeyDown(KEY_SPACE))
            player.jump();
        if (IsKeyDown(KEY_W))
            player.moveForward();
        if (IsKeyDown(KEY_S))
            player.moveBackward();
        if (IsKeyDown(KEY_A))
            player.moveLeft();
        if (IsKeyDown(KEY_D))
            player.moveRight();
        player.updateGravity();
    }
    for (int i = 0; i < enemies.size(); i++)
        UnloadModel(enemies[i].model);
    for (int i = 0; i < bullets.size(); i++)
        UnloadModel(bullets[i].model);
    for (int i = 0; i < staticBlocks.size(); i++)
        UnloadModel(staticBlocks[i].model);
    UnloadShader(shader);
    CloseWindow();

    return 0;
}
