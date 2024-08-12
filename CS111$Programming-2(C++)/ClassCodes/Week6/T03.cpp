#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream ifile;
    ifile.open("T01W.txt", ios::in);
    if (!ifile)
    {
        cout << "File open error" << endl;
        return -1;
    }

    // string str;
    char str[32];
    // while (!ifile.eof())
    while (ifile)
    {
        // getline(ifile, str, '\n');
        ifile.getline(str, 32); // use member function '\n' for delimiter
        cout << str << endl;
        // ifile >> str;
        // cout << str << " ";
        // str = "";
    }

    ifile.close();

    cout << "Done." << endl;

    return 0;
}