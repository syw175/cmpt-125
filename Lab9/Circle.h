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

#pragma once  // What is this???

class Circle {

private: 
    const double DEFAULT_VALUE = 10.0;  // Default value for radius? // Default xy = 0,0    
    int xCoordinate; 
    int yCoordinate; 
    double radius;

public: 
    // Default Constructor 
    // What is the relationship with the DEFAULT_VALUE? 
    Circle();

    // Constructor overloading?
    Circle(int xValue, int yValue, double radiusValue);

    // Destructor?

    // Methods    
    // const ensures that getter functions can not change class members

    // Get the xCoordinate value
    int getX() const;

    // Get the yCoordinate value
    int getY() const;

    // Get the radius value
    double getRadius() const;

    // Move the x and y coordinates by the offsets given
    void move(int horiz, int vert) const; 

    // Set the radius to the new value 
    void setRadius(double r);

    // Compute and return the area of the circle 
    double computeArea() const; 

    // Print the circle's member values 
    void displayCircle() const;

    // Returns true if a circle instances another circle
    bool intersect(Circle c) const;


}; // What is the semicolons for here??