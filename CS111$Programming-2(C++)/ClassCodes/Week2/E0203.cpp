#include <iostream>
#include <time.h>
using namespace std;

int getSum(int my_array[]);
int *getMax(int my_array[]);

int main()
{

    int my_array[100];
    int *max_el;

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
    cout << "Array with Random Numbers" << endl;
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

    max_el = getMax(my_array);

    cout << "====================================================================================" << endl;
    cout << "Sum of elements: " << getSum(my_array) << endl;
    cout << "The largest element is " << max_el[0] << " at the index of " << max_el[1] << endl;
    cout << "====================================================================================" << endl;

    return 0;
}

int getSum(int my_array[])
{

    int sum = 0;

    for (int i = 0; i < 100; i++)
    {
        sum += my_array[i];
    }

    return sum;
}

int *getMax(int my_array[])
{

    static int max_element[2];
    int max_value = 0;

    for (int i = 0; i < 100; i++)
    {
        if (max_value < my_array[i])
        {
            max_value = my_array[i];
            max_element[0] = max_value;
            max_element[1] = i;
        }
    }

    return max_element;
}