/*
 * Filename: InRectangle.c
 *
 * Description: Determines whether a point lies inside a rectangle. The point and rectangle
 *              are both specified using arrays of floating point values.
 * 
 * Author: Steven Wong
 * Date: June 15, 2022
 */


#include<stdio.h> 
#define POINTS 2
#define CORNERS 4


// Get the max of two floating point values
float max(float num1, float num2) { 
    return (num1 > num2 ) ? num1 : num2;
}


// Get the min of two floating point values
float min(float num1, float num2) { 
    return (num1 < num2 ) ? num1 : num2;
}


// Check if a point is within the range of a rectangle in a X-Y coordinate
int InRectangle (float pt[POINTS], float rect[CORNERS]) { 
  
  // Initialize floats values to check if point is in rectangle
  const float pointX = pt[0];
  const float pointY = pt[1];
  const float upperPointX = max(rect[0], rect[2]);
  const float upperPointY = max(rect[1], rect[3]);
  const float lowerPointX = min(rect[0], rect[2]);
  const float lowerPointY = min(rect[1], rect[3]);

  // If point X and point Y are within the bounds of the rectangle points, it must be in the rectangle
  if (pointX <= upperPointX && pointX >= lowerPointX) { 
    if (pointY <= upperPointY && pointY >= lowerPointY) { 
      return 1;
    }
  }
  return 0;  
}