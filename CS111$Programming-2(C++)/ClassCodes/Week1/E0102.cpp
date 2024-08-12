#include <iostream>
using namespace std;

int main(){

    string first_name, last_name;

    cout << "What is your first name?";
    cin >> first_name;
    cout << "What is your last name? ";
    cin >> last_name;
    cout << "==============================================" << endl; 
    cout << "Good Morning, " << first_name << " " << last_name << "." << endl; 
    
    return 0;
}