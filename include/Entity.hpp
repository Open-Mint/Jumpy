#pragma once

#include "raylib.h"

#include <vector>

class Entity
{
private:
    Vector2 position;
    float radius;
public:
    Entity();
    void draw();
    void move(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    ~Entity();
};