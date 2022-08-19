// Program: List.h
// Description: An array based list class 
//	Date: August 15, 2022
//	Name: Steven Wong

#pragma once 
using namespace::std; 

class List {

    private:
        // Default Capacity
        static const int DEFAULT_CAPACITY = 15;
        // Array
        int *data;
        // Element Count
        int elementCount;

    public:
        // Constructor 
        List(); 
        
        // Deep Copy 
        List (const List& lst);

        // Destructor
        ~List(); 

        // Get Element Count
        int getElementCount() const;

        // Insert "newElement" at "newPosition" in the List and returns
        // true if successful, false otherwise
        bool insert(int newElement, int position); 

        // Remove the element at "position" in the List and returns 
        // true if successful, false otherwise 
        bool remove(int position);

        // Remove all elements from the list 
        void removeAll();

        // Returns the element at "position" in the List
        int getElement(int position) const;

        // Prints all elements in the list as well as element count
        void displayList();
};
