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
    player.move(obstacle.getLeftObstacle(), obstacle.getRightObstacle());
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