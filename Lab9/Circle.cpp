/*
* Circle.cpp
*
* Description: This class models a circle with a (x, y) integer coordinate 
*              representing the circle's center and a double radisu. The x 
*              and y integers can be positive or negative. The radius must
*              have a value greater than 0.
*
* Author: Steven Wong
* Date: July 21, 2022
*/

#define _USE_MATH_DEFINES // for math constants
#include <iostream>  // for printing out data
#include <stdbool.h> // for booleans
#include <cmath>     // for computing area

#include "Circle.h"

using namespace std; 

// Initializes the circle to the default values
Circle::Circle() 
{
    this->xCoordinate = DEFAULT_COORD;
    this->yCoordinate = DEFAULT_COORD;
    this->radius = DEFAULT_RAD;
}

// Initializes the circle to the given values
Circle::Circle(int xCoordinate, int yCoordinate, double radius)
{
    // If the radius is less than 0, set it to 0
    if (radius <= 0.0) radius = DEFAULT_RAD;

    // Initialize the class members
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    this->radius = radius;
}

// Returns the xCoordinate value
int Circle::getX() const
{
    return this->xCoordinate;
} 

// Returns the yCoordinate value
int Circle::getY() const 
{
    return this->yCoordinate;
}

// Returns the radius value
double Circle::getRadius() const 
{
    return this->radius;
}

// Moves the x and y coordinates by the offsets given
void Circle::move(int horiz, int vert)
{
    this->xCoordinate += horiz;
    this->yCoordinate += vert;
}

// Sets the radius to the new value
void Circle::setRadius(double r) 
{
    // If the radius is less than 0, set it to 10.0
    if (r <= 0.0) r = DEFAULT_RAD;

    // Set the radius to the new value
    this->radius = r;
}

// Computes and returns the area of the circle
double Circle::computeArea() const 
{
    return M_PI * pow(getRadius(), 2);
}

// Prints the circle's member values
void Circle::displayCircle() const 
{
    cout << "\nx = " << getX() << ", y = " << getY() << ", radius = " << getRadius() << endl;
}

// Returns true if the circles intersect, false otherwise
// Based on this definition: https://planetcalc.com/8098/
bool Circle::intersect(Circle c) const
{
    // Calculate the distance between the two circles centers
    double distance = sqrt(pow(c.getX() - getX(), 2) + pow(c.getY() - getY(), 2));

    // If the distance is 0, and r1 == r2, then the circles are the same 
    if (distance == 0 && getRadius() == c.getRadius())
    {
        return false;
    }
    // If distance is greater than the sum of the two radii, they are separate
    else if (distance > (getRadius() + c.getRadius()))
    {
        return false;
    }
    // If the distance is less than the absolute value of r1-r2, the circles are concentric
    else if (distance < abs(getRadius() - c.getRadius()))
    {
        return false;
    }
    else 
    {
        return true;
    }
}