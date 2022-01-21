#pragma once

#include "raylib.h"

#include <vector>

class Obstacle
{
private:
    std::vector<std::vector<Vector2>> LeftObstacle;
    std::vector<std::vector<Vector2>> RightObstacle;
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
public:
    Obstacle();
    void draw();
    ~Obstacle();
};