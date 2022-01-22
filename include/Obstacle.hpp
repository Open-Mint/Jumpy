#pragma once

#include "raylib.h"

#include <vector>

class Obstacle
{
private:
    std::vector<std::vector<Vector2>> LeftObstacle;
    std::vector<std::vector<Vector2>> RightObstacle;
    Rectangle platform;
public:
    Obstacle();
    void draw();
    ~Obstacle();
private:
    void setVectorLeft();
    void setVectorRight();
};