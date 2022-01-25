#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}, hasStarted{false}
{
    dummyPosition = position;

    camera.target = position;
    camera.zoom = 1.f;
    camera.rotation = 0.f;
    camera.offset = position;

    constexpr char L = 'L';
    constexpr char R = 'R';
    
    for(int i = 0; i < 14; ++i)
    {
        if((i + 1) % 2 == 0)
            side.emplace_back(R);
        else
            side.emplace_back(L);
    }

    for(int i = 0; i < 12; ++i)
        states.emplace_back(true);
}

void Entity::playerView()
{
    camera.target = dummyPosition;
}

Camera2D Entity::getView()
{
    return camera;
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

const bool Entity::start() const
{
    return hasStarted;
}

void Entity::move(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle)
{
    constexpr float speed = 400.f;
    static bool gravity = false;
    if(gravity)
    {
        position.y += 80.f * GetFrameTime();
    }

    static Vector2 LeftPoint1 = {LeftObstacle[6].at(2).x + 100.f, LeftObstacle[6].at(2).y};
    static Vector2 RightPoint1 = {RightObstacle[6].at(2).x - 100.f, RightObstacle[6].at(2).y};
    static Vector2 LeftPoint2 = {LeftObstacle[5].at(2).x + 100.f, LeftObstacle[5].at(2).y};
    static Vector2 RightPoint2 = {RightObstacle[5].at(2).x - 100.f, RightObstacle[5].at(2).y};
    static Vector2 LeftPoint3 = {LeftObstacle[4].at(2).x + 100.f, LeftObstacle[4].at(2).y};
    static Vector2 RightPoint3 = {RightObstacle[4].at(2).x - 100.f, RightObstacle[4].at(2).y};
    static Vector2 LeftPoint4 = {LeftObstacle[3].at(2).x + 100.f, LeftObstacle[3].at(2).y};
    static Vector2 RightPoint4 = {RightObstacle[3].at(2).x - 100.f, RightObstacle[3].at(2).y};
    static Vector2 LeftPoint5 = {LeftObstacle[2].at(2).x + 100.f, LeftObstacle[2].at(2).y};
    static Vector2 RightPoint5 = {RightObstacle[2].at(2).x - 100.f, RightObstacle[2].at(2).y};
    static Vector2 LeftPoint6 = {LeftObstacle[1].at(2).x + 100.f, LeftObstacle[1].at(2).y};
    static Vector2 RightPoint6 = {RightObstacle[1].at(2).x - 100.f, RightObstacle[1].at(2).y};
    static Vector2 LeftPoint7 = {LeftObstacle[0].at(2).x + 100.f, LeftObstacle[0].at(2).y};
    static Vector2 RightPoint7 = {RightObstacle[0].at(2).x - 100.f, RightObstacle[0].at(2).y + 80.f};
    // last one acts weird
    
    static int counter = 0;
    if(!states[0])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint1, position)), speed * GetFrameTime()));
        
        if(position.x <= LeftPoint1.x)
        {
            gravity = true;
            states[0] = true;
        }
    }
    else
    if(!states[1])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint1, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint1.x)
        {
            gravity = true;
            states[1] = true;
        }
    }
    else
    if(!states[2])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint2, position)), speed * GetFrameTime()));
    
        if(position.x <= LeftPoint2.x)
        {
            gravity = true;
            states[2] = true;
        }
    }
    else
    if(!states[3])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint2, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint2.x)
        {
            gravity = true;
            states[3] = true;
        }
    }
    else
    if(!states[4])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint3, position)), speed * GetFrameTime()));
    
        if(position.x <= LeftPoint3.x)
        {
            gravity = true;
            states[4] = true;
        }
    }
    else
    if(!states[5])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint3, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint3.x)
        {
            gravity = true;
            states[5] = true;
        }
    }
    else
    if(!states[6])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint4, position)), speed * GetFrameTime()));
    
        if(position.x <= LeftPoint4.x)
        {
            gravity = true;
            states[6] = true;
        }
    }
    else
    if(!states[7])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint4, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint4.x)
        {
            gravity = true;
            states[7] = true;
        }
    }
    else
    if(!states[8])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint5, position)), speed * GetFrameTime()));
    
        if(position.x <= LeftPoint5.x)
        {
            gravity = true;
            states[8] = true;
        }
    }
    else
    if(!states[9])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint5, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint5.x)
        {
            gravity = true;
            states[9] = true;
        }
    }
    else
    if(!states[10])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(LeftPoint6, position)), speed * GetFrameTime()));
    
        if(position.x <= LeftPoint6.x)
        {
            gravity = true;
            states[10] = true;
        }
    }
    else
    if(!states[11])
    {
        gravity = false;
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(Vector2Subtract(RightPoint7, position)), speed * GetFrameTime()));
    
        if(position.x >= RightPoint7.x)
        {
            gravity = true;
            states[11] = true;
        }
    }
}

void Entity::moveCamera()
{
    if(hasStarted == true)
        dummyPosition.y -= GetFrameTime() * increaseInSpeed;
}

void Entity::handleInput()
{
    if(IsKeyPressed(KEY_SPACE))
    {
        static int counter = 0;
        if(side[0] == 'L' && counter == 0)
        {
            counter++;
            states[0] = false;
            hasStarted = true;
        }
        else
        if(side[1] == 'R' && counter == 1)
        {
            counter++;
            states[1] = false;
        }
        else
        if(side[2] == 'L' && counter == 2)
        {
            counter++;
            states[2] = false;
        }
        else
        if(side[3] == 'R' && counter == 3)
        {
            counter++;
            states[3] = false;
        }
        else
        if(side[4] == 'L' && counter == 4)
        {
            counter++;
            states[4] = false;
        }
        else
        if(side[5] == 'R' && counter == 5)
        {
            counter++;
            states[5] = false;
        }
        else
        if(side[6] == 'L' && counter == 6)
        {
            counter++;
            states[6] = false;
        }
        else
        if(side[7] == 'R' && counter == 7)
        {
            counter++;
            states[7] = false;
        }
        else
        if(side[8] == 'L' && counter == 8)
        {
            counter++;
            states[8] = false;
        }
        else
        if(side[9] == 'R' && counter == 9)
        {
            counter++;
            states[9] = false;
        }
        else
        if(side[10] == 'L' && counter == 10)
        {
            counter++;
            states[10] = false;
        }
        else
        if(side[11] == 'R' && counter == 11)
        {
            counter++;
            states[11] = false;
            increaseInSpeed += 30.f;
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