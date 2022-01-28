#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}, gen{rd()}, cod{1, 3}, random{cod(gen)}, isBoosting{false}
{
}

Vector2 Entity::getPosition()
{
    return position;
}

void Entity::move()
{
    if(direction.y == UP.y && direction.x == UP.x)
    {
        position.y -= GetFrameTime() * 100.f;
        hasMoved = true;
    }
    if(direction.y == DOWN.y && direction.x == DOWN.x)
    {
        position.y += GetFrameTime() * 100.f;
        hasMoved = true;
    }
    if(direction.y == LEFT.y && direction.x == LEFT.x)
    {
        position.x -= GetFrameTime() * 100.f;
        hasMoved = true;
    }
    if(direction.y == RIGHT.y && direction.x == RIGHT.x)
    {
        position.x += GetFrameTime() * 100.f;
        hasMoved = true;
    }
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
        if(random == 2)
        {
            DrawText("Press E", 550.f / 2.f, 650.f / 2.f, 55, GREEN);
            static int count = 0;
            if(IsKeyPressed(KEY_E))
            {
                if(count == 0) 
                    isBoosting = true;
                if(count == 1)
                    isBoosting = false;
                count++;
            }
        }
        speed = 150.f;
    }

    if(random == 3)
    {
        if(isBoosting)
        {   
            speed = 0.f;
        }
        else if(!isBoosting && dif != 2)
        {
            DrawText("Press E", 550.f / 2.f, 650.f / 2.f, 55, GRAY);    
        }
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