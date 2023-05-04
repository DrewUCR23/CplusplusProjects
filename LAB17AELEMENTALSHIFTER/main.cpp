/*
* Drew Gonzales
* Professor Paul Conrad
* 3/22/2023
* CIS-17A POINTERS Assignment-Elemental Shifter
*
*
* OBJECTIVE OF ASSIGNMENT:Write a function named ArrayElementShift that accepts a
*  floating point array and the array’s size as its parameter arguments.
* The function should create and return a new array that is one element larger than the argument array.
* The first element of the new array should be set to 0.0. Element 0 of the argument array should be copied to element 1 of the new array,
* element 1 of the argument array should be copied to
* element 2 of the new array, and so forth. The function should return a pointer to the new array.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

float*ArrayElementShift(float* ARRAY, int SIZE) {
    // Allocate memory for the new array
    float* NEWARRAY = new float[SIZE + 1];
    // Set the first element to 0.0
    NEWARRAY[0] = 0.0f;
    // Copy the elements of ARRAY to NEWARRAY
    for (int i = 0; i < SIZE; i++) {
        NEWARRAY[i + 1] = ARRAY[i];
    }

    // Return a pointer to the new array
    return NEWARRAY;
}

int main(int argc, char** argv) {
    // Size of the array
    int SIZE = 4;

    // Declare the array and initialize it with some values
    float* ARRAY = new float[SIZE];
    ARRAY[0] = 3.4f;
    ARRAY[1] = 5.4f;
    ARRAY[2] = 6.2f;
    ARRAY[3] = 8.7f;

    // Call the ArrayElementShift function to create a new array
    float* NEWARRAY = ArrayElementShift(ARRAY, SIZE);

    // Output the values of the original array
    std::cout << "Original Array: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::fixed << std::setprecision(1) << ARRAY[i] << (i < SIZE - 1 ? ", " : "");
    }
    std::cout << std::endl;

    // Print the new array
    std::cout << "New Array: ";
    for (int i = 0; i < SIZE + 1; i++) {
        std::cout << std::fixed << std::setprecision(1) << NEWARRAY[i] << (i < SIZE ? ", " : "");
    }
    std::cout << std::endl;

    // Delete the dynamically allocated arrays accordingly
    delete[] ARRAY;
    delete[] NEWARRAY;

    return 0;
}
