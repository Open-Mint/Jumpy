#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}
{
}

void Entity::collisionWithObsticle(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle)
{
    for(auto& left : LeftObstacle)
    {
        if(CheckCollisionPointTriangle({position.x, position.y - 10.f}, left.at(0), left.at(1), left.at(2)))
            CloseWindow();
    }
    for(auto& right : RightObstacle)
    {
        if(CheckCollisionPointTriangle({position.x, position.y - 10.f}, right.at(0), right.at(1), right.at(2)))
            CloseWindow();
    }
}

void Entity::move()
{
    if(direction.y == UP.y && direction.x == UP.x)
        position.y -= GetFrameTime() * 100.f;
    if(direction.y == DOWN.y && direction.x == DOWN.x)
        position.y += GetFrameTime() * 100.f;
    if(direction.y == LEFT.y && direction.x == LEFT.x)
        position.x -= GetFrameTime() * 100.f;
    if(direction.y == RIGHT.y && direction.x == RIGHT.x)
        position.x += GetFrameTime() * 100.f;
}

void Entity::handleInput()
{
    if(IsKeyDown(KEY_UP))
    {
        direction = UP;
    }
    else
    if(IsKeyDown(KEY_DOWN))
    {
        direction = DOWN;
    }
    else
    if(IsKeyDown(KEY_LEFT))
    {
        direction = LEFT;
    }
    else
    if(IsKeyDown(KEY_RIGHT))
    {
        direction = RIGHT;
    }
    else
    {
        direction = IDLE;
    }
}

void Entity::keepObstaclesMoving(std::vector<std::vector<Vector2>>& LeftObstacle, 
                                 std::vector<std::vector<Vector2>>& RightObstacle, int dif)
{
    float speed = 20.f;
    if(dif == 0) // EASY
    {
        speed = speed;
    }
    else
    if(dif == 1) // MEDIUM
    {
        speed = 50.f;
    }
    else
    if(dif == 2) // HARD
    {
        speed = 150.f;
    }
    for(int i = 6; i >= 0; --i)
    {
        if(position.y < RightObstacle[i].at(1).y)
        {
            LeftObstacle[i].at(0).x += GetFrameTime() * speed;
            LeftObstacle[i].at(1).x += GetFrameTime() * speed;
            LeftObstacle[i].at(2).x += GetFrameTime() * speed;
        }
        if(position.y < LeftObstacle[i].at(1).y)
        {
            RightObstacle[i].at(0).x -= GetFrameTime() * speed;
            RightObstacle[i].at(1).x -= GetFrameTime() * speed;
            RightObstacle[i].at(2).x -= GetFrameTime() * speed;
        }
    }
}

void Entity::draw()
{
    DrawCircle(position.x, position.y, radius, BLACK);
}

Entity::~Entity()
{
}