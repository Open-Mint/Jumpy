#include "../include/Game.hpp"

Game::Game()
{
    InitWindow(WindowWidth, WindowHeight, "Jumpy!");
}

void Game::clear() const
{
    ClearBackground(GRAY);
}

void Game::update(float dt)
{   
    player.collisionWithObsticle(obstacle.getLeftObstacle(), obstacle.getRightObstacle());
    player.handleInput();
    player.move();
    obstacle.newWave();
    player.keepObstaclesMoving(obstacle.getLeftObstacle(), obstacle.getRightObstacle(), obstacle.level);
}

void Game::render()
{
    player.draw();
    obstacle.draw();
}

void Game::MainLoop()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
            clear();
            update();
            render();
        EndDrawing();
    }
}

void Game::run()
{
    MainLoop();
}

Game::~Game()
{
    CloseWindow();
}