#include <iostream>
using namespace std;

void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

int main()
{
    int x = 5;
    int y = 10;
    cout << "Before swap: x= " << x << ", y= " << y << endl;
    // swap(&x, &y);
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    return 0;
}
