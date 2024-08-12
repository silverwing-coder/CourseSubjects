#include <iostream>
using namespace std;

int main(){

    string first_name, last_name;
    int score;

    cout << "First Name: " ;
    cin >> first_name;
    cout << "Last Name: " ;
    cin >> last_name;
    cout << "Score: " ;
    cin >> score;

    cout << "==============================================" << endl; 
    
    if (score >= 90){
        cout << first_name << " " << last_name << "'s grade is 'A'." << endl; 
    }
    else if (score >= 80){
        cout << first_name << " " << last_name << "'s grade is 'B'." << endl; 
    }
    else if (score >= 70){
        cout << first_name << " " << last_name << "'s grade is 'C'." << endl; 
    }
    else if (score >= 60){
        cout << first_name << " " << last_name << "'s grade is 'D'." << endl; 
    }
    else{
        cout << first_name << " " << last_name << "'s grade is 'F'." << endl; 
    }
    
    return 0;
}