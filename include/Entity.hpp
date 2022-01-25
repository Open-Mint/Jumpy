#pragma once

#include "raylib.h"

#include "raymath.h"

#include <vector>

class Entity
{
private:
    Vector2 position;
    float radius;
    Camera2D camera;
    Vector2 dummyPosition;
    std::vector<bool> states;
    std::vector<char> side; // vector of char to find which side is player on
    bool hasStarted;
    float increaseInSpeed = 20.f;
public:
    Entity();
    void draw();
    void handleInput();
    void collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    void playerView();
    const bool start() const;
    Camera2D getView();
    void move(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    void moveCamera();
    ~Entity();
};