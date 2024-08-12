#include <iostream>
#include <time.h>
using namespace std;

int *shuffleArray(int my_array[]);

int main()
{

    int my_array[100];
    int *shuffled_array;

    /** Initialize array elements */
    srand(time(NULL));
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        my_array[i] = rand() % 100;
    }

    // cout << "Size: " << sizeof(my_array) << endl;
    // cout << "Size: " << end(my_array) - begin(my_array) << endl;
    // cout << "Size: " << sizeof(my_array)/sizeof(my_array[0]) << endl;

    cout << "====================================================================================" << endl;
    cout << "Array before Shuffling" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 100; i++)
    {
        // element = rand()%100;
        cout << "\t" << my_array[i] << ",";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }

    shuffled_array = shuffleArray(my_array);
    cout << "====================================================================================" << endl;
    cout << "Array after Shuffling" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 100; i++)
    {
        // element = rand()%100;
        cout << "\t" << my_array[i] << ",";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }

    return 0;
}

int *shuffleArray(int my_array[])
{

    int shuffle_index, temp;

    for (int i = 0; i < 100; i++)
    {
        shuffle_index = rand() % 100;
        temp = my_array[i];
        my_array[i] = my_array[shuffle_index];
        my_array[shuffle_index] = temp;
    }

    return my_array;
}