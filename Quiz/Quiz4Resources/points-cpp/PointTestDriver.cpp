/* PointTestDriver.cpp - D100 */
#include <iostream>
#include <cassert>
#include "Points.hpp"
using namespace std;

int main() 
{
    // int aPoint = 0;
    // Points myPoints;
    // cout << "\nmyPoints object has been instantiated." << endl << endl;
    // cout << "***Printing: "; myPoints.printPoints(); cout << endl << endl;
    // cout << "***Inserting: ";
    
    // while ( scanf( "%d", &aPoint ) != EOF ) 
    // {
    //     myPoints.append(aPoint);
    // }

    // cout << "***" << endl;
    // cout << "***Printing: ";
    // myPoints.printPoints();
    // cout << endl;



    // Create new instance of points
    Points myPoints;

    // Add 2, 5, and 5 to myPoints
    myPoints.append(2);
    myPoints.append(5);
    myPoints.append(5);

    // Check that there exists two points of 5 in myPoints
    assert(myPoints.pointCount(5) == 2);

    // Remove duplicates of 5 from myPoints
    assert(myPoints.removeDuplicates(5) == 2);

    // Check that point 5 no longer exists in myPoints
    assert(myPoints.pointCount(5) == 0);

    // Check that removeDuplicates works when no duplicates exist
    assert(myPoints.removeDuplicates(5) == 0);

    // Validate that printPoints works
    cout << "Expected: There are 1 points in the array of size 10.\nThese points are: 2\n" << endl; 
    cout << "Actual:   "; myPoints.printPoints(); cout << endl;

    // Add 9, 10, 11, 12, 1, 5, 7 to myPoints
    myPoints.append(9);
    myPoints.append(10);
    myPoints.append(11);
    myPoints.append(12);
    myPoints.append(1);
    myPoints.append(5);
    myPoints.append(7);


    // Check that elements were correctly added to myPoints
    cout << "Expected: There are 8 points in the array of size 10.\nThese points are: 2, 9, 10, 11, 12, 1, 5, 7\n" << endl;
    cout << "Actual:   "; myPoints.printPoints(); cout << endl;

    // Sort myPoints
    myPoints.sorting();

    // Check that myPoints is sorted
    cout << "Expected: There are 8 points in the array of size 10.\nThese points are: 1, 2, 5, 7, 9, 10, 11, 12\n" << endl;
    cout << "Actual:  "; myPoints.printPoints(); cout << endl;

    return 0;
} 