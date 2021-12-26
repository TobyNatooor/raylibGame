#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include "./include/raylib.h"
#define RLIGHTS_IMPLEMENTATION
#include "./include/rlights.h"
#include "./Player.h"
#include "Enemy.h"
#include "Block.h"

using std::vector;

class MainLoop
{
public:
    vector<Bullet> bullets = {};
    vector<Enemy> enemies = {};
    vector<Block> staticBlocks = {};

    Shader shader;
    Light light;
    Player player = Player(Vector3{0.0f, 0.0f, 0.0f}, Vector3{1.0f, 2.0f, 1.0f}, staticBlocks, 0.15f, 0.02f, 0.6f);

    MainLoop(vector<Block> _staticBlocks,
             vector<Enemy> _enemies,
             vector<Bullet> _bullets,
             Player _player, Shader _shader, Light _light);
    void loop();
    void emscriptenLoop();
    void end();
};
