/*
* Circle.cpp
*
* Description: This class models a circle with a (x, y) integer coordinate 
*              representing the circle's center and a double radisu. The x 
*              and y integers can be positive or negative. The radius must
*              have a value greater than 0.
*
* Author: Steven Wong
* Date: July 19, 2022
*/


#include <iostream>  // for printing out data
#include <stdbool.h> // for booleans

#include "Circle.h"

using namespace std; 

// Default Constructor
Circle::Circle() 
{
    this->xCoordinate = DEFAULT_COORD;
    this->yCoordinate = DEFAULT_COORD;
    this->radius = DEFAULT_RAD;
}

// Constructor
Circle::Circle(int xCoordinate, int yCoordinate, double radius)
{
    // Need to adjsut for variant checking
    this->xCoordinate = xCoordinate;
    this->yCoordinate = xCoordinate;
    this->radius = radius;
}


// Getter method for x coordinate, returns int
int Circle::getX() const
{
    return this->xCoordinate;
} 


// Getter method for y coordinate, returns int 
int Circle::getY() const 
{
    return this->yCoordinate;
}


// Getter method for radius, returns double 
double Circle::getRadius() const 
{
    return this->radius;
}

// Change x and y coordinates members by horiz and vert
void Circle::move(int horiz, int vert)
{
    this->xCoordinate += horiz;
    this->yCoordinate += vert;
}

// TO-DO: void setRadius(double r) -> setter func to change radius to r or 10.0 if r is invalid num 
void Circle::setRadius(double r) 
{
    if (r <= 0.0) 
    {
        this->radius = DEFAULT_RAD;
    } 
    else 
    {
        this->radius = r;
    }
}

// TO-DO: double computeArea() -> compute and return the area of the circle 
double Circle::computeArea() const 
{
    return PI * this->radius * this->radius;
}

// TO-DO: void displayCircle() -> "Circle with radius 10.0 at point x = 12, y = 17"
void Circle::displayCircle() const 
{
    cout << "Circle with radius " << getRadius() 
    << " at point x = " << getX() << ", y = " << getY();
}

// TO-DO bool intersect(Circle c) -> returns true if c intersects the circle 
// https://www.bbc.co.uk/bitesize/guides/z9pssbk/revision/4
bool Circle::intersect(Circle c) const
{
    return true;
}