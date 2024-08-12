// C++ program to illustrate bad_alloc using class bad_alloc
#include <exception>
#include <iostream>
using namespace std;

// Function to illustrate bad_alloc
void createArray(int N)
{
    try
    {
        // Create an array of length N
        int *array = new int[N];

        // If created successfully then print the message
        cout << "Array created successfully"
             << " of length " << N << " \n";
    }

    // Check if the memory was allocated or not using class bad_alloc
    catch (bad_alloc &e)
    { // If not, print the error message
        cout << e.what()
             << " for array of length "
             << N << " \n";
    }
}

int main()
{
    // Function call to create an array of 1000 size
    createArray(1000);

    // Function call to create an array of 1000000000 size
    createArray(1000000000);
    return 0;
}