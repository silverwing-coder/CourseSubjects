#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ofstream ofile;
    ofile.open("T01W.txt");
    ofile << "John"
          << " "
          << "T"
          << " "
          << "Smith"
          << " " << 90 << endl;
    ofile << "Eric"
          << " "
          << "K"
          << " "
          << "Jones"
          << " " << 85 << endl;
    ofile.close();

    cout << "Done." << endl;

    return 0;
}