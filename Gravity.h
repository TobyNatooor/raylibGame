#pragma once
#include <vector>
#include "./include/raylib/raylib.h"
#include "Block.h"
#include "Entity.h"

using std::vector;

class Gravity : Entity
{
public:
    bool isJumping;
    bool isFalling;

    Gravity(vector<Block> _staticBlocks);
};
