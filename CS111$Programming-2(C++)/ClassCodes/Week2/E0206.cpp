#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int main()
{

    int my_matrix[7][7];
    int max_row_sum = 0, max_row_index = -1;
    int max_col_sum = 0, max_col_index = -1;

    /** Initialize array elements */
    srand(time(NULL));
    srand(time(0));

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            my_matrix[i][j] = rand() % 100;
            // cout << setw(5) << my_matrix[i][j] << ",  ";
        }
        // cout << endl;
    }

    int row_sum;
    int col_sum[7] = {
        0,
    };
    cout << "\n===================================================================" << endl;
    cout << "\t\t\t MATRIX" << endl;
    cout << "===================================================================" << endl;
    for (int i = 0; i < 7; i++)
    {
        row_sum = 0;
        for (int j = 0; j < 7; j++)
        {
            cout << setw(5) << my_matrix[i][j] << "   ";
            row_sum += my_matrix[i][j];
            col_sum[j] += my_matrix[i][j];
        }
        cout << ": " << setw(7) << row_sum << endl;

        if (row_sum > max_row_sum)
        {
            max_row_sum = row_sum;
            max_row_index = i;
        }
    }

    cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < 7; i++)
    {
        if (col_sum[i] > max_col_sum)
        {
            max_col_sum = col_sum[i];
            max_col_index = i;
        }
        cout << setw(5) << col_sum[i] << "   ";
    }
    cout << "\n===================================================================" << endl;
    cout << "The maximum row sunm of the matrix is " << max_row_sum << " at row " << max_row_index << endl;
    cout << "The maximum column sunm of the matrix is " << max_col_sum << " at column " << max_col_index << endl;
    cout << "===================================================================" << endl;

    return 0;
}
