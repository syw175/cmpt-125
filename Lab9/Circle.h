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

#pragma once

class Circle {

private: 
    const int DEFAULT_COORD = 0;
    const double DEFAULT_RAD = 10.0;
    int xCoordinate; 
    int yCoordinate; 
    double radius;

public: 
    // Valid initialization of class members in C++11
    // https://stackoverflow.com/questions/45291142/what-is-a-c11-extension-wc11-extensions
    // Circle() = default;

    // Default Constructor 
    Circle();
    
    // Constructor overloading
    Circle(int xCoordinate, int yCoordinate, double radius);

    // Get the xCoordinate value
    int getX() const;

    // Get the yCoordinate value
    int getY() const;

    // Get the radius value
    double getRadius() const;

    // Move the x and y coordinates by the offsets given
    void move(int horiz, int vert); 

    // Set the radius to the new value 
    void setRadius(double r);

    // Compute and return the area of the circle 
    double computeArea() const; 

    // Print the circle's member values 
    void displayCircle() const;

    // Returns true if a circle instances another circle
    bool intersect(Circle c) const;
};