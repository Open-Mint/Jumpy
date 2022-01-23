#pragma once

#include "raylib.h"

#include <vector>

class Obstacle
{
private:
    std::vector<std::vector<Vector2>> LeftObstacle;
    std::vector<std::vector<Vector2>> RightObstacle;
    Rectangle platform;
    Rectangle LeftScreenClear;
    Rectangle RightScreenClear;
public:
    Obstacle();
    std::vector<std::vector<Vector2>>& getLeftObstacle();
    std::vector<std::vector<Vector2>>& getRightObstacle();
    void move(bool state);
    void draw();
    ~Obstacle();
private:
    void setVectorLeft();
    void setVectorRight();
    void setClearingBackground();
};