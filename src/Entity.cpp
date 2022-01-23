#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}
{
    dummyPosition = position;

    camera.target = position;
    camera.zoom = 1.f;
    camera.rotation = 0.f;
    camera.offset = position;
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

const bool Entity::hasStarted() const
{
    return states[0];
}

void Entity::move(std::vector<std::vector<Vector2>>& LeftObstacle, std::vector<std::vector<Vector2>>& RightObstacle)
{
    for(int i = 0; i < 13; ++i)
        states.emplace_back(true);

    static float increaseInSpeed = 5.f; 
    if(states[0] == false)
        dummyPosition.y -= GetFrameTime() * increaseInSpeed;

    if(IsKeyPressed(KEY_SPACE))
    {
        std::vector<char> side; // vector of char to find which side is player on
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');
        side.emplace_back('R');
        side.emplace_back('L');

        if(dummyPosition.y == position.y)
        {
            increaseInSpeed += 20.f; // may be causing bad things in future
        }
        if(side[0] == 'L' && states[0])
        {
            position = {LeftObstacle[6].at(2).x + 100.f, LeftObstacle[6].at(2).y};
            states[0] = false;
        }
        else
        if(side[1] == 'R' && states[1])
        {
            position = {RightObstacle[6].at(2).x - 100.f, RightObstacle[6].at(2).y};
            states[1] = false;
        }
        else
        if(side[2] == 'L' && states[2])
        {
            position = {LeftObstacle[5].at(2).x + 100.f, LeftObstacle[5].at(2).y};
            states[2] = false;
        }
        else
        if(side[3] == 'R' && states[3])
        {
            position = {RightObstacle[5].at(2).x - 100.f, RightObstacle[5].at(2).y};
            states[3] = false;
        }
        else
        if(side[4] == 'L' && states[4])
        {
            position = {LeftObstacle[4].at(2).x + 100.f, LeftObstacle[4].at(2).y};
            states[4] = false;
        }
        else
        if(side[5] == 'R' && states[5])
        {
            position = {RightObstacle[4].at(2).x - 100.f, RightObstacle[4].at(2).y};
            states[5] = false;
        }
        else
        if(side[6] == 'L' && states[6])
        {
            position = {LeftObstacle[3].at(2).x + 100.f, LeftObstacle[3].at(2).y};
            states[6] = false;
        }
        else
        if(side[7] == 'R' && states[7])
        {
            position = {RightObstacle[3].at(2).x - 100.f, RightObstacle[3].at(2).y};
            states[7] = false;
        }
        else
        if(side[8] == 'L' && states[8])
        {
            position = {LeftObstacle[2].at(2).x + 100.f, LeftObstacle[2].at(2).y};
            states[8] = false;
        }
        else
        if(side[9] == 'R' && states[9])
        {
            position = {RightObstacle[2].at(2).x - 100.f, RightObstacle[2].at(2).y};
            states[9] = false;
        }
        else
        if(side[10] == 'L' && states[10])
        {
            position = {LeftObstacle[1].at(2).x + 100.f, LeftObstacle[1].at(2).y};
            states[10] = false;
        }
        else
        if(side[11] == 'R' && states[11])
        {
            position = {RightObstacle[1].at(2).x - 100.f, RightObstacle[1].at(2).y};
            states[11] = false;
        }
        else
        if(side[12] == 'L' && states[12])
        {
            position = {LeftObstacle[0].at(2).x + 100.f, LeftObstacle[0].at(2).y};
            states[12] = false;
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