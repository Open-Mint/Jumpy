#pragma once

#include "raylib.h"

#include <vector>

class Entity
{
private:
    Vector2 position;
    float radius;
    
    Vector2
    UP = {0, -1},
    DOWN = {0, 1},
    LEFT = {-1, 0},
    RIGHT = {1, 0},
    IDLE = {0, 0};

    Vector2 direction;
public:
    Entity();
    void draw();
    void handleInput();
    void collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    
    void move();
    
    void keepObstaclesMoving(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle, int dif);
    ~Entity();
};