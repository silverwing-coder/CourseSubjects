#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream ifile;
    ifile.open("T01W.txt");
    if (!ifile)
    {
        cout << "File open error" << endl;
        return -1;
    }

    string str;
    while (!ifile.eof())
    {
        getline(ifile, str, '\n');
        cout << str << endl;
    }

    ifile.close();

    cout << "Done." << endl;

    return 0;
}