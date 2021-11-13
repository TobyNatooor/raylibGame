
#include "./Block.h"

Block::Block(Vector3 _position, Vector3 _dimension, Color _color, Shader shader)
{
    position = _position;
    dimension = _dimension;
    color = _color;
    model = LoadModelFromMesh(GenMeshCube(_dimension.x, _dimension.y, _dimension.z));
    model.materials[0].shader = shader;
}

bool Block::hasCollidedWith(Vector3 objPosition)
{
    Vector3 blockCornerOne = {position.x - dimension.x / 2,
                              position.y - dimension.y / 2,
                              position.z - dimension.z / 2};
    Vector3 blockCornerTwo = {position.x + dimension.x / 2,
                              position.y + dimension.y / 2,
                              position.z + dimension.z / 2};

    if (blockCornerOne.x < objPosition.x && objPosition.x < blockCornerTwo.x &&
        blockCornerOne.y < objPosition.y && objPosition.y < blockCornerTwo.y &&
        blockCornerOne.z < objPosition.z && objPosition.z < blockCornerTwo.z)
    {
        return true;
    }

    return false;
}

void Block::draw()
{
    DrawModel(model, position, 1.0f, color);
}
