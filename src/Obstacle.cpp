#include "../include/Obstacle.hpp"

Obstacle::Obstacle()
: v1{0, 80}, v2{80, 0}, v3{0, 0}
{

}

void Obstacle::draw()
{

    std::vector<Vector2> triangle;
    triangle.emplace_back(v1);
    triangle.emplace_back(v2);
    triangle.emplace_back(v3);


    for(int i =  0; i < 8; ++i)
    {

        LeftObstacle.emplace_back(triangle);
        triangle[0].y += 80.f;
        triangle[1].y += 80.f;
        triangle[2].y += 80.f;
    }

    for(int i = 0; i < 8; ++i)
    {
        DrawTriangle(LeftObstacle[i].at(0), LeftObstacle[i].at(1), LeftObstacle[i].at(2), DARKGRAY);
    }
}

Obstacle::~Obstacle()
{
}