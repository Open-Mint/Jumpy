#pragma once

#include "raylib.h"

class Entity
{
private:
    Vector2 position;
    float radius;
public:
    Entity();
    void draw();
    ~Entity();
};