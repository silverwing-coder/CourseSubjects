#include <iostream>
using namespace std;

int *min(int &x, int &y)
{
    if (x < y)
        return (&x);
    else
        return (&y);
}

int main()
{
    int x = 5;
    int y = 10;
    int *p;
    p = min(x, y);
    cout << "The min number is " << *p << endl;
    return 0;
}
