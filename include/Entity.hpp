#pragma once

#include "raylib.h"

#include <vector>
#include <random>

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

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> cod;
    int random;
public:
    Entity();
    void draw();
    void handleInput();
    void collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, 
                               std::vector<std::vector<Vector2>>& RightObstacle,
                               Rectangle& platform);
    
    void move();
    
    Vector2 &getPosition();

    bool hasMoved;
    bool isBoosting;
    int count = 0;
    float speed = 100.f;

    void keepObstaclesMoving(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle, int dif);
    
    void generateNewRandom();

    ~Entity();
};