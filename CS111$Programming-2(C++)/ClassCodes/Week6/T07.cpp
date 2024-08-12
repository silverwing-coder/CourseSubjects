#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream inFile("letters.txt", ios::in);
    char ch;

    // inFile.seekg(5L, ios::beg);
    // inFile.get(ch);
    // cout << "5 bytes from beginning : " << ch << endl;
    // inFile.seekg(-10L, ios::end);
    // inFile.get(ch);
    // cout << "10 bytes from end : " << ch << endl;
    // inFile.seekg(3L, ios::cur);
    // inFile.get(ch);
    // cout << "3 bytes from current : " << ch << endl;

    inFile.seekg(3L, ios::cur);
    inFile.get(ch);
    cout << ch;

    inFile.close();
    return 0;
}