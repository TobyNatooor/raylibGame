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

class Main
{
    std::vector<Bullet> bullets = {};
    std::vector<Enemy> enemies = {};
    std::vector<Block> staticBlocks = {};

    Shader shader;
    Light light;
    Player player;

public:
    Main(std::vector<Block> _staticBlocks,
         std::vector<Enemy> _enemies,
         std::vector<Bullet> _bullets,
         Player _player, Shader _shader, Light _light);
    void loop();
    void end();
};
