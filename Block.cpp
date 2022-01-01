#include "Block.h"

Block::Block(Vector3 _position, Vector3 _dimension, Color _color, Shader _shader)
    : Object(_position, _color)
{
    dimension = _dimension;
    model = LoadModelFromMesh(GenMeshCube(_dimension.x, _dimension.y, _dimension.z));
    model.materials[0].shader = _shader;
}

bool Block::hasCollidedWithPoint(Vector3 objPosition)
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
        return true;
    return false;
}

bool Block::hasCollidedWithBlock(Vector3 objPosition, Vector3 objDimensions)
{
    if (CheckCollisionBoxes(
            BoundingBox{Vector3{position.x - dimension.x / 2,
                                position.y - dimension.y / 2,
                                position.z - dimension.z / 2},
                        Vector3{position.x + dimension.x / 2,
                                position.y + dimension.y / 2,
                                position.z + dimension.z / 2}},
            BoundingBox{Vector3{objPosition.x - objDimensions.x / 2,
                                objPosition.y - objDimensions.y / 2,
                                objPosition.z - objDimensions.z / 2},
                        Vector3{objPosition.x + objDimensions.x / 2,
                                objPosition.y + objDimensions.y / 2,
                                objPosition.z + objDimensions.z / 2}}))
        return true;
    return false;
}

bool Block::hasCollidedWithSphere(Vector3 spherePosition, float sphereRadius)
{
    if (CheckCollisionBoxSphere(
            BoundingBox{Vector3{position.x - dimension.x / 2,
                                position.y - dimension.y / 2,
                                position.z - dimension.z / 2},
                        Vector3{position.x + dimension.x / 2,
                                position.y + dimension.y / 2,
                                position.z + dimension.z / 2}},
            spherePosition, sphereRadius))
        return true;
    return false;
}
