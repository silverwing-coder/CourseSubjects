#include <iostream>
// #include <iomanip>
using namespace std;

int main(){

    float f_degree;

    cout << "Enter a degree in Fahrenheit: ";
    cin >> f_degree;
    cout << "==============================================" << endl; 
    // cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);
    cout << "Fahrenheit " << f_degree << " is " << (f_degree - 32) * 5/9 << " in Celsius.\n"; 
    // cout << "Fahrenheit " << setw(10) << f_degree << " is " << setw(10) << (f_degree - 32) * 5/9 << " in Celsius.\n"; 
    // cout << "Fahrenheit " << setprecision(10) << f_degree << " is " << (f_degree - 32) * 5/9 << " in Celsius.\n"; 
    
    return 0;
}