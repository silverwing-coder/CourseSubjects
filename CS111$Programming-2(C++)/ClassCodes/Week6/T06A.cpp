#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream outFile("bi_testA.txt", ios::out); //| ios::binary);
    int buffer[10] = {1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120};
    for (int i = 0; i < 10; i++)
    {
        // cout << buffer[i];
        outFile << buffer[i] << " ";
    }
    outFile.close();

    fstream inFile("bi_testA.txt", ios::in);
    string str;
    while (!inFile.eof())
    {
        inFile >> str;
        cout << str << " ";
    }
    inFile.close();
    return 0;
}
