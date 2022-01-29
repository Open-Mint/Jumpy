#include "../include/Game.hpp"

Game::Game()
: exitWindow{false}, WindowState{true}, gameOver{false}
{
    InitWindow(WindowWidth, WindowHeight, "Jumpy!");

    RestartButton.height = 100.f;
    RestartButton.width = 150.f;
    RestartButton.x = 550.f / 2.f - 70.f;
    RestartButton.y = 650.f / 2.f - 50.f;

    QuitButton.height = 100.f;
    QuitButton.width = 150.f;
    QuitButton.x = 550.f / 2.f - 70.f;
    QuitButton.y = 650.f / 2.f + 60.f;
}

void Game::drawStartText() const
{
    DrawText("Hello. Welcome! Move with\n WASD.\nTry to avoid triangles!\n*whispering*Press E when possible...",
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
    if(WindowState)
    {    
        collisionWithObsticle(obstacle.getLeftObstacle(), obstacle.getRightObstacle(), obstacle.getPlatform(), player.getPosition());
        player.handleInput();
        obstacle.newWave();
        player.keepObstaclesMoving(obstacle.getLeftObstacle(), obstacle.getRightObstacle(), obstacle.level);
        player.move();
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !WindowState)
    {
        restart();
        quit();
    }
}

void Game::render()
{
    if(WindowState)
    {
        player.draw();
        obstacle.draw();
    }
    else
    if(!WindowState)
    {
        if(!gameOver)
            DrawText("Phew...That was close!", 20.f, 550.f / 2.f - 200.f, 48, BLACK);
        else
            DrawText("Game over", 160, 80, 48, BLACK);
          
        DrawRectangleRec(RestartButton, {60, 60, 60, 255});
        DrawRectangleRec(QuitButton, {60, 60, 60, 255});
        DrawRectangleLinesEx(RestartButton, 2.f, BLACK);
        DrawRectangleLinesEx(QuitButton, 2.f, BLACK);
        DrawText("Restart", 550 / 2 - 65, 300, 36, BLACK);
        DrawText("Quit", 550 / 2 - 30, 410, 36, BLACK);
    } 
}

void Game::MainLoop()
{
    while(!WindowShouldClose() && !exitWindow)
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

void Game::quit()
{
    if(GetMouseX() >= QuitButton.x  && GetMouseX() <= QuitButton.x + QuitButton.width && 
       GetMouseY() >= QuitButton.y && GetMouseY() <=  QuitButton.y + QuitButton.height)
    {
         exitWindow = true;
    }
}

void Game::restart()
{
    if(GetMouseX() >= RestartButton.x  && GetMouseX() <= RestartButton.x + RestartButton.width && 
       GetMouseY() >= RestartButton.y && GetMouseY() <=  RestartButton.y + RestartButton.height)
    {
        player.getPosition() = {550.f / 2.f, 550.f};
        obstacle.clearLeftVector();
        obstacle.clearRightVector();
        obstacle.setVectorLeft();
        obstacle.setVectorRight();
        obstacle.level = 0;
        player.count = 0;
        player.generateNewRandom();
        player.movementSpeed = 100.f;
        WindowState = true;
    }
}

void Game::collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, 
                                 std::vector<std::vector<Vector2>>& RightObstacle,
                                 Rectangle& platform, Vector2 position)
{
    if(obstacle.level > 2)
    {
        WindowState = false;
        gameOver = false;
    }
    if(position.x < 0.f)
    {
        WindowState = false;
        gameOver = true;
    }
    if(position.x > 550.f)
    {
        WindowState = false;
        gameOver = true;
    }
    if(position.y < 0.f)
    {
        WindowState = false;
        gameOver = true;
    }
    if(position.y > platform.y)
    {
        WindowState = false;
        gameOver = true;
    }
    for(auto& left : LeftObstacle)
    {
        if(CheckCollisionPointTriangle({position.x, position.y - 10.f}, left.at(0), left.at(1), left.at(2)) ||
           CheckCollisionPointTriangle({position.x, position.y + 10.f}, left.at(0), left.at(1), left.at(2))
          )
        {
            WindowState = false;
            gameOver = true;
        }
    }
    for(auto& right : RightObstacle)
    {
        if(CheckCollisionPointTriangle({position.x, position.y - 10.f}, right.at(0), right.at(1), right.at(2)) ||
           CheckCollisionPointTriangle({position.x, position.y + 10.f}, right.at(0), right.at(1), right.at(2))
          )
        {
            WindowState = false;
            gameOver = true;
        }
    }
}
Game::~Game()
{
    CloseWindow();
}