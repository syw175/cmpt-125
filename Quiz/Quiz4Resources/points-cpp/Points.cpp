/* Points.cpp - D100 */
#include <iostream>
#include <algorithm>
#include "Points.hpp"

using namespace std;

// Constructor: Constructs a "Points" object that has no points yet
//              (numOfPoints = 0), that has an array "points" not yet allocated
//              (points = NULL), but can contain up to 10 points (arraySize = 10)
    //              when it will be allocated.
Points::Points() : numOfPoints(0), points(NULL), arraySize(10)
{
}

// Destructor
Points::~Points() 
{
    if ( points != NULL ) 
    {
        delete [] points;
        points = NULL;
    }

    numOfPoints = 0;
    arraySize = 0;
}

// Description: Insert "thePoint" in the next unoccupied cell in the array.
// Return 0 if this method is done successful, 1 otherwise.

// Requirements: The array is not kept in any particular order.
// Duplicated points are allowed in the array.
// If the array is full, "thePoint" is not appended.
int Points::append( int thePoint ) 
{
    int done = 0;

    // If the array is full ...
    if ( numOfPoints == arraySize )
        done = 1;
    else {
    // Dynamically allocate memory for the array
    // if this is the first time "append" method is called.
    if ( numOfPoints == 0 ) 
    {
    points = new int[arraySize];
    if ( points == NULL )
        done = 1; // Memory allocation failed.
    }
    if ( points != NULL )
    {

    // Insert "thePoint" in the next unoccupied cell in the array.
        points[numOfPoints] = thePoint;
        numOfPoints++; // One more point in the array
    }
 }

 return done;
}

// Description: Returns the number of times "thePoint" is found in the array.
// Requirements: This method does not print and only has one "return" statement.
// You must implement this method without using "break" statements.
// No further instructions are given. It is for you to decide
// what to do based on what you have learnt this semester and
// your software development experience
unsigned int Points::pointCount( int thePoint )
{
    // Initialize the counter
    unsigned int count = 0;
    // Loop through the array
    for ( int i = 0; i < this->numOfPoints; i++ )
    {
        // If the current point is the same as the point we are looking for... 
        if ( this->points[i] == thePoint )
            // Increment the counter
            count++;
    }
    // Return the counter
    return count;
}


// Description:  Remove all occurrences of "thePoint" from the array.
//               Returns the number of times "thePoint" has been removed from the array.
// Requirements: The array does not have to be kept in any particular order.
//               This methods does not release dynamically allocated memory.
//               This method does not print and only has one "return" statement.
//               You must implement this method without using "break" statements.
//               No further instructions are given. It is for you to decide
//               what to do based on what you have learnt this semester and
//               your software development experience.
unsigned int Points::removeDuplicates( int thePoint )
{
    // Initialize the counter
    unsigned int count = 0;
    // Loop through the array
    for ( int i = 0; i < this->numOfPoints; i++ )
    {
        // If the current point is the same as the point we are looking for... 
        if ( this->points[i] == thePoint )
        {
            // Remove the point
            this->points[i] = this->points[numOfPoints - 1];
            // Decrease the number of points
            // this->numOfPoints--;
            // Increment the counter
            count++;
        }
    }
    // Decrease the number of points
    this->numOfPoints -= count;
    // Return the counter
    return count;
}


// Description: Prints the content of this object.
//              Test case 1: If we append the points 2 2 3 4 5 5
//              into this object, this method will produce the following:
//              There are 6 points in the array of size 10.
//              These points are: 2, 2, 3, 4, 5, 5
void Points::printPoints() 
{
    cout << "There are " << this->numOfPoints << " points in the array of size " << this->arraySize << endl;
    cout << "These points are: ";
    for ( int i = 0; i < this->numOfPoints; i++ )
    {
        cout << this->points[i] << " ";
    }
    cout << endl;
}


// Description: Sorts the points in the array in ascending order.
void Points::sorting()
{
    // Sort the array
    // https://cplusplus.com/reference/algorithm/sort/
    sort( this->points, this->points + this->numOfPoints );
}
