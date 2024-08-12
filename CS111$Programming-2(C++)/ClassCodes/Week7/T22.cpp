#include <exception>
#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    try
    {
        if (num2 == 0)
            // throw num2;
            throw num1;
        cout << num1 << " / " << num2 << " is " << (num1 / num2) << endl;
    }
    catch (int e)
    {
        cout << "Exception: an integer " << e << " cannot be divided by zero." << endl;
        // cout << "Exception: " << e << endl;
        // throw;
    }

    cout << "Next statements... execution continues " << endl;

    return 0;
}