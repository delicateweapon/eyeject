#pragma once

class Matrix3x3 {
public:  
    /* TODO */
};

class Point2D {
public:
    float x;
    float y;
    float w; /* always 1 */

    Point2D();
    Point2D(float x, float y);

    float magnitude_squared();
    float magnitude();

    static float distance_squared(Point2D& p1, Point2D& p2);
    static float distance(Point2D& p1, Point2D& p2);
};