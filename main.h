#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <raylib.h>
#define RLIGHTS_IMPLEMENTATION
#include <rlights.h>
#include "Player.h"
#include "Enemy.h"
#include "Block.h"

class MainLoop
{
public:
    std::vector<Bullet> bullets = {};
    std::vector<Enemy> enemies = {};
    std::vector<Block> staticBlocks = {};

    Shader shader;
    Light light;
    Player player = Player(Vector3{0.0f, 0.0f, 0.0f}, Vector3{1.0f, 2.0f, 1.0f}, staticBlocks, 0.15f, 0.02f, 0.6f);

    MainLoop(std::vector<Block> _staticBlocks,
             std::vector<Enemy> _enemies,
             std::vector<Bullet> _bullets,
             Player _player, Shader _shader, Light _light);
    void loop();
    void emscriptenLoop();
    void end();
};
