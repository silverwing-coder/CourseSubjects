#include <iostream>
using namespace std;

int cube(int y)
{
    y = y * y * y;
    return y;
};

// void cube(int &y)
// {
//     y = y * y * y;
// };

// int &cube(int &y)
// {
//     y = y * y * y;
//     return y;
// };

int main()
{
    int y = 10, num = 5;
    cout << "y before cube: " << y << endl;
    // cube(y);
    // y = cube(y);

    // cube(y) = num;
    cout << "y after cube: " << y << endl;

    return 0;
}