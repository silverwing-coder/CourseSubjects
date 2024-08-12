#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
using namespace std;

int main()
{
    const int ROW_MAX = 20, COL_MAX = 2;

    int my_matrix[ROW_MAX][COL_MAX];
    float dist_matrix[ROW_MAX][ROW_MAX] = {
        0,
    };

    float shortest_dist = 1000000;
    int from_index, to_index;

    /** Initialize array elements */
    // srand(time(NULL));
    srand(time(0));

    cout << "\n==========================================" << endl;
    cout << "\t POSITION VECTORs" << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < ROW_MAX; i++)
    {
        cout << "\t" << setw(2) << i << ". [";
        for (int j = 0; j < COL_MAX; j++)
        {
            my_matrix[i][j] = rand() % 20 - 10;
            cout << setw(3) << my_matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }

    float dist = 0;
    for (int i = 0; i < ROW_MAX; i++)
    {
        for (int j = i + 1; j < ROW_MAX; j++)
        {
            dist = 0;
            for (int k = 0; k < COL_MAX; k++)
            {
                dist += pow(((float)my_matrix[i][k] - (float)my_matrix[j][k]), 2);
                // cout << dist << endl;
            }

            if (sqrt(dist) < shortest_dist)
            {
                shortest_dist = sqrt(dist);
                from_index = i;
                to_index = j;
            }
            dist_matrix[i][j] = sqrt(dist);
        }
    }

    cout << fixed << showpoint << setprecision(2);
    // for (int i = 0; i < ROW_MAX; i++)
    // {
    //     cout << "From point-" << setw(2) << i;
    //     for (int j = i + 1; j < ROW_MAX; j++)
    //     {
    //         cout << setw(7) << dist_matrix[i][j];
    //     }
    //     cout << endl;
    // }

    cout << "----------------------------------------------------------------------------" << endl;
    cout << "The shortest distance " << shortest_dist << " comes from point " << from_index << " [" << my_matrix[from_index][0] << ", " << my_matrix[from_index][1] << "] to point " << to_index << " [" << my_matrix[to_index][0] << ", " << my_matrix[to_index][1] << "]" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    return 0;
}
