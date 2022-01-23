#pragma once

#include "raylib.h"

#include <vector>

class Entity
{
private:
    Vector2 position;
    float radius;
    Camera2D camera;
    Vector2 dummyPosition;
public:
    Entity();
    void draw();
    void move(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    void collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle);
    void playerView();
    Camera2D getView();
    ~Entity();
};