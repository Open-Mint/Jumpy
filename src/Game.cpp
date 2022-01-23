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
    player.move(obstacle.getLeftObstacle(), obstacle.getRightObstacle());
    obstacle.move(player.hasStarted());
    player.playerView();
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
          BeginMode2D(player.getView());
            clear();
            update();
            render();
          EndMode2D();
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