#include "Vector.hpp"

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector::~Vector()
{
}

void Vector::add(const Vector &vec)
{
    x += vec.x;
    y += vec.y;
}

void Vector::scale(float alpha)
{
    x *= alpha;
    y *= alpha;
}
