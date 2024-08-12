#include <iostream>
// #include <cctype>
using namespace std;

int main(int argc, char *argv[]){

    const float ADULT = 30.00, CHILD = 10.00, SENIOR = 15.00, FAMILY = 50.00;

    char residency;
    int membership_type;

    cout << "\t\t ---------------------" << endl;
    cout << "\t\t YMCA MEMBERSHIP MENU." << endl;
    cout << "\t\t ---------------------" << endl;

    cout << "Residency of Winston-Salem ('Y' or 'N'): ";
    cin >> residency;
    // cout << toupper(residency) << endl;
    // cout << toupper('Y') << endl;
    
    if(toupper(residency) != toupper('Y') && toupper(residency) != toupper('N')){
        cout << "Residency selection error." << endl;
    }else{
        cout << "Membership Type ( 1, , 2, or 3)" << endl;
        cout << "\t1. Standard Adult Membership" << endl;
        cout << "\t2. Child Membership" << endl;
        cout << "\t3. Senior Membership" << endl;
        cout << "\t4. Family Membership" << endl;
        cin >> membership_type;

        if(membership_type < 1 || membership_type > 4){
            cout << "Membership selection error." << endl;
        }else{

            cout.setf(ios::fixed | ios::showpoint);
            // cout.setf(fixed | showpoint);
            cout.precision(2);

            if(toupper(residency) == toupper('Y') && membership_type == 1){
                cout << "Your membership fee is $ " << ADULT * 0.7; 
            }
            else if(toupper(residency) == toupper('N') && membership_type == 1){
                cout << "Your membership fee is $ " << ADULT; 
            }
            else if(toupper(residency) == toupper('Y') && membership_type == 2){
                cout << "Your membership fee is $ " << CHILD * 0.7; 
            }
            else if(toupper(residency) == toupper('N') && membership_type == 2){
                cout << "Your membership fee is $ " << CHILD; 
            }
            else if(toupper(residency) == toupper('Y') && membership_type == 3){
                cout << "Your membership fee is $ " << SENIOR * 0.7; 
            }
            else if(toupper(residency) == toupper('N') && membership_type == 3){
                cout << "Your membership fee is $ " << SENIOR; 
            }
            else if(toupper(residency) == toupper('Y') && membership_type == 4){
                cout << "Your membership fee is $ " << FAMILY * 0.7; 
            }
            else if(toupper(residency) == toupper('N') && membership_type == 4){
                cout << "Your membership fee is $ " << FAMILY; 
            }            
        }
    }
    
    return 0;
}
