#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int *nArray, row, col, cnt;
    row = 3;
    col = 5;
    nArray = new int[row * col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            nArray[i * col + j] = i + j;
        }
    }

    for (int k = 0; k < row * col; k++)
    {
        cout << nArray[k] << endl;
    }

    delete[] nArray;

    return 0;
}
