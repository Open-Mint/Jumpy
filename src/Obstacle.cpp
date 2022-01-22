#include "../include/Obstacle.hpp"

Obstacle::Obstacle()
: platform{0.f, 560.f, 550.f, 90.f}
{
    setVectorLeft();
    setVectorRight();
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
}

Obstacle::~Obstacle()
{
}