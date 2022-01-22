#include "../include/Entity.hpp"

Entity::Entity()
: position{550.f / 2.f, 550.f}, radius{10.f}
{
}

void Entity::draw()
{
    DrawCircle(position.x, position.y, radius, BLACK);
}

Entity::~Entity()
{
}