#pragma once

#include "raylib.h"

#include "Obstacle.hpp"
#include "Entity.hpp"

class Game
{
private:
    static constexpr int WindowWidth = 550;
    static constexpr int WindowHeight = 650;
    Obstacle obstacle;
    Entity player;
public:
    Game();
    void run();
    ~Game();
private:
    void MainLoop();
    void clear() const;
    void update(float dt=GetFrameTime());
    void render();
};