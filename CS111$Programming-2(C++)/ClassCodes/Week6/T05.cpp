#include <iostream>
#include <fstream>
using namespace std;

void printState(fstream &file)
{
    cout << "File Status: " << endl;
    cout << "eof bit: " << file.eof() << endl;
    cout << "fail bit: " << file.fail() << endl;
    cout << "bad bit: " << file.bad() << endl;
    cout << "good bit: " << file.good() << endl;
    file.clear();
}

int main()
{

    fstream tfile;
    tfile.open("T01W.txt", ios::out | ios::app);
    printState(tfile);
    tfile.close();

    tfile.open("T01W.txt", ios::in);
    tfile << 3;
    printState(tfile);
    tfile.close();

    cout << "Done." << endl;
    return 0;
}