#include <iostream>
using namespace std;

#define PI 3.14159

float getArea(float radius)
{
    return PI * radius * radius;
}

float getArea(float width, float height)
{
    return width * height;
}

int main(int argc, char *argv[])
{
    float radius;
    cout << "Enter the radius of a clrcle: ";
    cin >> radius;
    cout << "Area of a circle with radius of " << radius << " is " << getArea(radius) << endl;

    float width, height;
    cout << "Enter the 'width' and 'height' of a rectangle: ";
    cin >> width >> height;
    cout << "Area of a rectangle with width of " << width << " and height of " << height
         << " is " << getArea(width, height) << endl;

    return 0;
}