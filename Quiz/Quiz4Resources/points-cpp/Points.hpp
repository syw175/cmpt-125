/* Points.hpp - D100 */
class Points {

private:
	unsigned int numOfPoints;  // Number of points in the array
	unsigned int arraySize;    // Size of the array (number of cells in array)
	int * points;              // Pointer to an array of points (int)

public:
	// Constructor: Constructs a "Points" object that has no points yet
	//              (numOfPoints = 0), that has an array "points" not yet allocated
	//              (points = NULL), but can contain up to 10 points (arraySize = 10)
	//              when it will be allocated.
	Points();


	// Destructor
	~Points();


	// Description:  Insert "thePoint" in the next unoccupied cell in the array.
	//               Return 0 if this method is done successful, 1 otherwise.
	// Requirements: The array is not kept in any particular order.
	//               Duplicated points are allowed in the array.
	//               If the array is full, "thePoint" is not appended.
	int append( int thePoint );


	// Description:  Returns the number of times "thePoint" is found in the array.
	// Requirements: This method does not print and only has one "return" statement.
	//               You must implement this method without using "break" statements.
	//               No further instructions are given. It is for you to decide
	//               what to do based on what you have learnt this semester and
	//               your software development experience.
	unsigned int pointCount( int thePoint );


	// Description:  Remove all occurrences of "thePoint" from the array.
	//               Returns the number of times "thePoint" has been removed from the array.
	// Requirements: The array does not have to be kept in any particular order.
	//               This methods does not release dynamically allocated memory.
	//               This method does not print and only has one "return" statement.
	//               You must implement this method without using "break" statements.
	//               No further instructions are given. It is for you to decide
	//               what to do based on what you have learnt this semester and
	//               your software development experience.
	unsigned int removeDuplicates( int thePoint );


	// Description: Prints the content of this object.
	//              Test case 1: If we append the points 2 2 3 4 5 5
	//              into this object, this method will produce the following:
	//              There are 6 points in the array of size 10.
	//              These points are: 2, 2, 3, 4, 5, 5

	//				Test case 2: If we append the points 1 2 3 1 2 3123 4
	//              into this object, this method will produce the following:
	//              There are 10 points in the array of size 10.
	//              These points are: 1, 2, 3, 1, 2, 3, 1, 2, 3, 4

	//   			Test case 3: If we append the points 10 11 12 13 14 15 16 17 18 19 20 21 22 23
	//              into this object, this method will produce the following:
	//              There are 10 points in the array of size 10.
	//              These points are: 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	
	//              Test case 4: If we append the points 2 2 2 2
	//              into this object, this method will produce the following:
	//              There are 4 points in the array of size 10.
	//              These points are: 2, 2, 2, 2
	void printPoints( );


	// Description: Sorts the points in the array in ascending order.
	//              Feel free to use this method if you need it!
	void sorting( );
};