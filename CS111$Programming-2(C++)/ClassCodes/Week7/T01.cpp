#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1 = "Washingon";
    string s2 = "California";
    cout << "The first character in s1 is " << s1[0] << endl;
    cout << "s1 + s2 is " << s1 + s2 << endl;
    cout << "s1 < s2 ? is " << (s1 < s2) << endl;

    cout << "===========================================" << endl;
    cout << "The first character in s1 is " << s1.operator[](0) << endl;
    cout << "s1 + s2 is " << operator+(s1, s2) << endl;
    cout << "s1 < s2 ? is " << operator<(s1, s2) << endl;

    // vector<int> v;
    // v.push_back(3);
    // v.push_back(5);

    // cout << "The first element iv v is " << v[0] << endl;
    // cout << "===========================================" << endl;
    // cout << "The first element iv v is " << v.operator[](0) << endl;

    return 0;
}