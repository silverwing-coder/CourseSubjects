#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{

    Rational r1(4, 2);
    Rational r2(2, 3);
    cout << "r1 is " << r1.toString() << endl;
    cout << "r2 is " << r2.toString() << endl;

    cout << "r1.compareTo(r2) is " << (r1.compareTo(r2)) << endl;
    cout << "r1.operator<(r2) is " << (r1.operator<(r2) ? "true" : "false") << endl;
    cout << "r1 < r2 is " << ((r1 < r2) ? "true" : "false") << endl;
    cout << "r2.compareTo(r1) is " << (r2.compareTo(r1)) << endl;
    cout << "r2.operator<(r1) is " << (r2.operator<(r1) ? "true" : "false") << endl;
    cout << "r2 < r1 is " << ((r2 < r1) ? "true" : "false") << endl;

    cout << "r1.add(r2) is " << r1.add(r2).toString() << endl;
    cout << "r1.operator+(r2) is " << r1.operator+(r2).toString() << endl;
    cout << "r1 + r2 is " << (r1 + r2).toString() << endl;
    cout << "r1[0] is " << r1[0] << endl;
    cout << "r1[1] is " << r1[1] << endl;

    return 0;
}