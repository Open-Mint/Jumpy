#include "../include/Obstacle.hpp"

Obstacle::Obstacle()
: platform{0.f, 560.f, 550.f, 90.f}
{
    setVectorLeft();
    setVectorRight();
    setClearingBackground();
}

void Obstacle::setClearingBackground()
{
    LeftScreenClear.height = 650.f;
    LeftScreenClear.width  = 300.f;
    LeftScreenClear.x = -300.f;
    LeftScreenClear.y = 0.f;

    RightScreenClear.height = 650.f;
    RightScreenClear.width  = 300.f;
    RightScreenClear.x = 550.f;
    RightScreenClear.y = 0.f;
}

void Obstacle::setVectorLeft()
{
    Vector2 v1 = {0, 80};
    Vector2 v2 = {80, 40};
    Vector2 v3 = {0, 0};

    std::vector<Vector2> LeftTriangle;

    LeftTriangle.emplace_back(v1);
    LeftTriangle.emplace_back(v2);
    LeftTriangle.emplace_back(v3);

    for(int i = 0; i < 7; ++i)
    {
        LeftObstacle.emplace_back(LeftTriangle);

        LeftTriangle[0].y += 80.f;
        LeftTriangle[1].y += 80.f;
        LeftTriangle[2].y += 80.f;
    }
}

void Obstacle::setVectorRight()
{
    Vector2 v1 = {470, 0};
    Vector2 v2 = {550, 40};
    Vector2 v3 = {550, -40};

    std::vector<Vector2> RightTriangle;
    
    RightTriangle.emplace_back(v1);
    RightTriangle.emplace_back(v2);
    RightTriangle.emplace_back(v3);
    
    for(int i = 0; i < 7; ++i)
    {
        RightObstacle.emplace_back(RightTriangle);
    
        RightTriangle[0].y += 80.f;
        RightTriangle[1].y += 80.f;
        RightTriangle[2].y += 80.f;
    }
}

std::vector<std::vector<Vector2>>& Obstacle::getLeftObstacle()
{
    return LeftObstacle;
}

std::vector<std::vector<Vector2>>& Obstacle::getRightObstacle()
{
    return RightObstacle;
}

void Obstacle::move()
{
    for(auto& left : LeftObstacle)
    {
        left.at(0).x += GetFrameTime() * 5.f;
        left.at(1).x += GetFrameTime() * 5.f;
        left.at(2).x += GetFrameTime() * 5.f;
    }
    for(auto& right : RightObstacle)
    {
        right.at(0).x -= GetFrameTime() * 5.f;
        right.at(1).x -= GetFrameTime() * 5.f;
        right.at(2).x -= GetFrameTime() * 5.f;
    }
    LeftScreenClear.x += GetFrameTime() * 4.f;
    LeftScreenClear.width += GetFrameTime() * 1.f;

    RightScreenClear.x -= GetFrameTime() * 5.f;
    RightScreenClear.width += GetFrameTime() * 1.f;
}

void Obstacle::draw()
{
    Color color = {60, 60, 60, 255}; // darker gray
    
    for(auto &left : LeftObstacle)
    {
        DrawTriangle(left.at(0), left.at(1), left.at(2), color);
    }

    for(auto &right : RightObstacle)
    {
        DrawTriangle(right.at(0), right.at(1), right.at(2), color);
    }

    DrawRectangleRec(platform, color);
    DrawRectangleRec(LeftScreenClear, color);
    DrawRectangleRec(RightScreenClear, color);
}

Obstacle::~Obstacle()
{
}