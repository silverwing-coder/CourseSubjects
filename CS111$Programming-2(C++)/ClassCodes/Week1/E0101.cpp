/**
 * Author: SAM Park
 * Date: 07-Mar-2023
 * Version: 0.1
 * This is to calculate the area of a rectangle.
 * Input value: rectangle width and height
 * Output value: area (width * height)
*/

#include <iostream>
using namespace std;

int main(){

    // define identifiers : width(the width of rectangle), height(the height of rectangle)
    int width, height;
    cout << "This program calculates the area of a rectangle.";
    cout << "\nEnter the width of the rectangle: ";
    // input width value from standard input
    cin >> width;
    cout << "Enter the height of the rectangle: ";
    // input height value from standard input
    cin >> height;
    cout << "==============================================" << endl; 
    // print out the area of rectangle on standard output
    cout << "The area of the rectanble is " << width * height << " ." << endl; 
    
    return 0;
}