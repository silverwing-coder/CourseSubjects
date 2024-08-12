#include <iostream>
#include <ctime>
using namespace std;

int main(){

    int c_seconds, c_minutes, c_hours, seconds, minutes, hours;

    c_seconds = time(0);
    c_minutes = c_seconds / 60;
    seconds = c_seconds % 60;
    c_hours = c_minutes / 60;
    minutes = c_minutes % 60;
    hours = c_hours % 24;

    cout << "==============================================" << endl; 
    cout << "The current time is " << hours << " o'clock " << minutes << " minutes and " << seconds << " seconds in UTC.";
    
    return 0;
}