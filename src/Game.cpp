#include "../include/Game.hpp"

Game::Game()
{
    InitWindow(WindowWidth, WindowHeight, "Jumpy!");
}

void Game::drawStartText() const
{
    DrawText("Hello. Welcome! Move with\nUP, DOWN, LEFT, RIGHT arrows.\nTry to avoid triangles!\n*whispering*Press E when possible...",
              100.f, 0.f, 24, BLACK);
}

void Game::clear() const
{
    ClearBackground(GRAY);
}

void Game::update()
{   
    if(!player.hasMoved)
        drawStartText();
    player.collisionWithObsticle(obstacle.getLeftObstacle(), obstacle.getRightObstacle(), obstacle.getPlatform());
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