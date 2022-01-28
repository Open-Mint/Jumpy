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
    std::vector<std::vector<Vector2>>& getLeftObstacle();
    std::vector<std::vector<Vector2>>& getRightObstacle();
    Rectangle& getPlatform();
    void draw();
    void newWave();
    void clearRightVector();
    void clearLeftVector();
    ~Obstacle();
private:
    void setVectorLeft();
    void setVectorRight();
public:
    int level;
};