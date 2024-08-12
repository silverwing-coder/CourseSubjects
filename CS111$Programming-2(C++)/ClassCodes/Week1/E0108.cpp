#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){

    double f1 = 123456789.123456789;

    // cout << fixed << showpoint;
    // cout << setprecision(3);
    // cout << "Formatted number is " <<  f1 << endl;

	cout << "Formatted number of \'" << f1 ;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(3);
	cout << "\' is \'" << f1 <<"\'" << endl;


    return 0;
}
