#include "main.h"

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#endif

void displayDataWindow(Player player)
{
    // Converts string 'displayString' to char[] to displays it ingame
    std::string displayString =
        "FPS: " + std::to_string(GetFPS()) + "\n" +
        // std::to_string(GetScreenHeight()) + ", " +
        // std::to_string(GetScreenWidth()) + "," +
        // "\n[" +
        // std::to_string(player.mouseDeltaSum.x) + "," +
        // std::to_string(player.mouseDeltaSum.y) + "]," +
        // "\n" + std::to_string(player.isFalling) +
        "";
    char displayChar[1024];
    strcpy(displayChar, displayString.c_str());
    DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 220, 70, BLUE);
    DrawText(displayChar, 20, 20, 10, BLACK);
}

Main::Main(std::vector<Block> _staticBlocks, std::vector<Enemy> _enemies,
           std::vector<Bullet> _bullets, Player _player, Shader _shader, Light _light)
{
    staticBlocks = _staticBlocks;
    enemies = _enemies;
    bullets = _bullets;
    player = _player;
    shader = _shader;
    light = _light;
}

void Main::loop()
{
    UpdateLightValues(shader, light);
    player.updateCameraDirection();
    UpdateCamera(&player.camera);
    float cameraPos[3] = {player.camera.position.x, player.camera.position.y, player.camera.position.z};
    SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

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

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(player.camera);

    // Draw bullets
    for (Bullet &bullet : bullets)
    {
        bullet.move();
        bullet.draw();
    };
    // Draw enemies
    for (Enemy &enemy : enemies)
    {
        if (enemy.isHitByBullets(bullets))
            enemy.drawHit();
        else
            enemy.draw();
    };
    // Draw blocks
    for (Block &staticBlock : staticBlocks)
    {
        staticBlock.draw();
    };

    EndMode3D();

    displayDataWindow(player);

    EndDrawing();
}

void Main::end()
{
    for (Bullet &bullet : bullets)
        UnloadModel(bullet.model);
    for (Enemy &enemy : enemies)
        UnloadModel(enemy.model);
    for (Block &staticBlock : staticBlocks)
        UnloadModel(staticBlock.model);
    UnloadShader(shader);
    CloseWindow();
}

Main mainInit()
{
    int screenWidth = 1280;
    int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "C++ Game");

    // Shader
#if defined(__EMSCRIPTEN__)
    Shader shader = LoadShader("shaders/base_lighting.txt", "shaders/lighting.txt");
#else
    Shader shader = LoadShader("shaders/base_lighting.vs", "shaders/lighting.fs");
#endif
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    const int ambientLoc = GetShaderLocation(shader, "ambient");
    const float floatValue[4] = {0.1f, 0.1f, 0.1f, 1.0f};
    SetShaderValue(shader, ambientLoc, floatValue, SHADER_UNIFORM_VEC4);

    std::vector<Bullet> bullets = {};

    std::vector<Enemy> enemies = {};
    enemies.push_back(Enemy(Vector3{-16.0f, 2.5f, 0.0f}, Vector3{3.0f, 3.0f, 3.0f}, GREEN, shader));
    enemies.push_back(Enemy(Vector3{-16.0f, 8.5f, 0.0f}, Vector3{6.0f, 6.0f, 6.0f}, GREEN, shader));

    std::vector<Block> staticBlocks = {};
    staticBlocks.push_back(Block(Vector3{0, -5, 0}, Vector3{30.0f, 3.0f, 30.0f}, GREEN, shader));
    staticBlocks.push_back(Block(Vector3{-5.0f, -2.0f, -5.0f}, Vector3{3.0f, 3.0f, 3.0f}, GRAY, shader));
    staticBlocks.push_back(Block(Vector3{-7.0f, 2.0f, -7.0f}, Vector3{3.0f, 6.0f, 3.0f}, RED, shader));

    Light light = CreateLight(LIGHT_POINT, Vector3{0, 4, 0}, Vector3{0, 3, 0}, WHITE, shader);

    Player player = Player(Vector3{0.0f, 0.0f, 0.0f}, Vector3{1.0f, 2.0f, 1.0f}, staticBlocks, 0.15f, 0.02f, 0.6f);

    SetCameraMode(player.camera, CAMERA_CUSTOM);
    SetTargetFPS(60);
    DisableCursor();

    return Main(staticBlocks, enemies, bullets, player, shader, light);
}

Main m = mainInit();

void c_loop()
{
    m.loop();
}

int main(void)
{
#if defined(__EMSCRIPTEN__)
    emscripten_set_main_loop(c_loop, 0, 1);
#else
    while (!WindowShouldClose())
        m.loop();
#endif

    m.end();
    return 0;
}
