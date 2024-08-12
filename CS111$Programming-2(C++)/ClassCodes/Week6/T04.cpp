#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream ofile;
    ofile.open("T01W.txt", ios::out | ios::app);
    ofile << "Adam"
          << " "
          << "W"
          << " "
          << "Smith"
          << " " << 95 << endl;
    ofile.close();

    cout << "Done." << endl;

    return 0;
}