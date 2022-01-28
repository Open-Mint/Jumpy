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
    bool exitWindow;
    bool WindowState;
    bool gameOver;
    Rectangle RestartButton;
    Rectangle QuitButton;
public:
    Game();
    void run();
    ~Game();
private:
    void MainLoop();
    void clear() const;
    void update();
    void render();
    void drawStartText() const;
    void collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, 
                                     std::vector<std::vector<Vector2>>& RightObstacle,
                                     Rectangle& platform, Vector2 position);
};