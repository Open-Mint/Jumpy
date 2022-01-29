#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}, gen{rd()}, cod{1, 4}, random{cod(gen)}, isBoosting{false}, count{0}, speed{40.f}, movementSpeed{100.f}
{
}

Vector2& Entity::getPosition()
{
    return position;
}

void Entity::move()
{
    if(direction.y == UP.y && direction.x == UP.x)
    {
        position.y -= GetFrameTime() * movementSpeed;
        hasMoved = true;
    }
    if(direction.y == DOWN.y && direction.x == DOWN.x)
    {
        position.y += GetFrameTime() * movementSpeed;
        hasMoved = true;
    }
    if(direction.y == LEFT.y && direction.x == LEFT.x)
    {
        position.x -= GetFrameTime() * movementSpeed;
        hasMoved = true;
    }
    if(direction.y == RIGHT.y && direction.x == RIGHT.x)
    {
        position.x += GetFrameTime() * movementSpeed;
        hasMoved = true;
    }
}

void Entity::handleInput()
{
    if(IsKeyDown(KEY_W))
    {
        direction = UP;
    }
    else
    if(IsKeyDown(KEY_S))
    {
        direction = DOWN;
    }
    else
    if(IsKeyDown(KEY_A))
    {
        direction = LEFT;
    }
    else
    if(IsKeyDown(KEY_D))
    {
        direction = RIGHT;
    }
    else
    {
        direction = IDLE;
    }
}

void Entity::generateNewRandom()
{
    random = cod(gen);
}

void Entity::keepObstaclesMoving(std::vector<std::vector<Vector2>>& LeftObstacle, 
                                 std::vector<std::vector<Vector2>>& RightObstacle, int dif)
{
    static Color color = GREEN; 
    if(dif == 0) // EASY
    {
        speed = 40.f;
    }
    else
    if(dif == 1) // MEDIUM
    {
        speed = 100.f;
    }
    else
    if(dif == 2) // HARD
    {
        speed = 150.f;
        if(random == 2)
        {
            
            DrawText("Press E", 550.f / 2.f - 100.f, 650.f / 2.f, 55, color);

            if(IsKeyPressed(KEY_E))
            {   
                color = GRAY;
                if(count == 0)
                {
                    isBoosting = true;
                }
                else
                {
                    isBoosting = false;
                }
                count++;
            }
            else
            {
                color = GREEN;
            }
        
            if(isBoosting)
            {   
                speed = 0.f;
            }
        }
        if(random == 3)
        {
            
            DrawText("Press E", 550.f / 2.f - 100.f, 650.f / 2.f, 55, color);

            if(IsKeyPressed(KEY_E))
            {   

                color = GRAY;
                if(count == 0)
                {
                    isBoosting = true;
                }
                else
                {
                    isBoosting = false;
                }
                count++;
            }
            else
            {
                color = GREEN;
            }
        
            if(isBoosting)
            {   
                movementSpeed = 300.f;
            }
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