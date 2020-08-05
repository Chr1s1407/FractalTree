#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
const double PI = 3.1415926536f;

/*
This class implements a simple 2D Vector.
Therefor it contains two values, x and y.

Some basic operations, that are further needed,
are already implemented here.
*/
class Vector
{
public:
    double x,y;
    Vector():  x(0), y(0) {}
    Vector(double a, double b): x(a), y(b) {}
    ~Vector()    {    }

    /*
     Adds the Vector other to the given one.
     Returns the summed up Vector.
    */
    Vector operator+(const Vector& other)
    {
        return Vector(x+other.x, y+other.y);
    }

    /*
     Subtracts the Vector other from the given one.
     Returns the subtracted up Vector.
    */
    Vector operator-(const Vector& other)
    {
        return Vector(x-other.x, y-other.y);
    }

    /*
    Scales both, x and y, by the given factor.
    */
    void scale(double factor)
    {
        x = factor*x;
        y = factor*y;
    }

    /*
    Rotates the Vector by the given degree.
    Returns the rotated Vector.
    */
    Vector rotate(double degrees)
    {
        double theta = degrees * PI / 180.0;
        double c = cos(theta);
        double s = sin(theta);
        double newX = x*c - y*s;
        double newY = x*s + y*c;
        return Vector(newX, newY);
    }

};

#endif // VECTOR_H
