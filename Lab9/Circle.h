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
    const unsigned int defaultRadius = 10;  // Is this fine if I asign this to a double radius
    int xCoordinate; 
    int yCoordinate; 

public: 
    // const ensures that getter functions can not change class members

    // Get the xCoordinate value
    int getX() const;
    // Get the yCoordinate value
    int getY() const;



}; // What is the semicolons for here??