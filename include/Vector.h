#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>
const double PI = 3.1415926536f;

/*
This class implements a simple 2D Vector.
Therefor it contains two values, x and y.

Some basic operations, that are further needed,
are already implemented here.
*/
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Vector
{
private:
    T x,y;
public:
    Vector():  x(0), y(0) {}
    Vector(T a, T b): x(a), y(b) {}
    ~Vector()
    {
        std::cout << "Vector: Destructor" << std::endl;
    }

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
        T newX = x*c - y*s;
        T newY = x*s + y*c;
        return Vector(newX, newY);
    }

    /*
    Returns the first value of the vector (x).
    */
    T first()
    {
        return x;
    }

    /*
    Returns the second value of the vector (y).
    */
    T second()
    {
        return y;
    }

};

#endif // VECTOR_H
