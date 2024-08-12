#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream outFile("bi_test.dat", ios::out); //| ios::binary);
    int buffer[10] = {1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120};
    outFile.write((char *)buffer, sizeof(buffer));
    outFile.close();

    fstream inFile("bi_test.dat", ios::in);
    inFile.read((char *)buffer, sizeof(buffer));
    for (int i = 0; i < 10; i++)
    {
        cout << buffer[i] << " ";
    }
    inFile.close();
    return 0;
}
