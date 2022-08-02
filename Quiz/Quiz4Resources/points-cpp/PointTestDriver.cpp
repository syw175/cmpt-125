/* PointTestDriver.cpp - D100 */
#include <iostream>
#include "Points.hpp"
using namespace std;

int main() 
{
    int aPoint = 0;
    Points myPoints;
    cout << "\nmyPoints object has been instantiated." << endl << endl;
    cout << "***Printing: "; myPoints.printPoints(); cout << endl << endl;
    cout << "***Inserting: ";
    
    while ( scanf( "%d", &aPoint ) != EOF ) 
    {
        myPoints.append(aPoint);
    }

    cout << "***" << endl;
    cout << "***Printing: ";
    myPoints.printPoints();
    cout << endl;
    
    return 0;
} 