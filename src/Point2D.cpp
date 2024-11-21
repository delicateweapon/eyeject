#include "Point2D.hpp"

#include <cmath>

Point2D::Point2D(float x, float y)
{
    this->x = x;
    this->y = y;
    this->w = 1;
}

float Point2D::magnitude_squared()
{
    return this->x * this->x + this->y * this->y;
}

float Point2D::magnitude()
{
    return std::sqrt(magnitude_squared());
}

float Point2D::distance_squared(Point2D& p1, Point2D& p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y = p2.y;

    return dx * dx + dy * dy;
}

float Point2D::distance(Point2D& p1, Point2D& p2)
{
    return std::sqrt(distance_squared(p1, p2));
}
