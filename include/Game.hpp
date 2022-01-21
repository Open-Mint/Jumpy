#pragma once

#include "raylib.h"

#include "Obstacle.hpp"

class Game
{
private:
    static constexpr int WindowWidth = 550;
    static constexpr int WindowHeight = 650;
    Obstacle obstacle;
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