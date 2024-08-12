#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    int num_low, num_high, p_count = 0;
    bool prm;
    if (stoi(argv[1]) > stoi(argv[2]))
    {
        num_low = stoi(argv[2]);
        num_high = stoi(argv[1]);
    }
    else
    {
        num_low = stoi(argv[1]);
        num_high = stoi(argv[2]);
    }

    cout << "\n\t=============================================================================" << endl;
    cout << "\tPrime Numbers: " << endl;
    cout << "\t=============================================================================" << endl;
    for (int i = num_low; i < num_high; i++)
    {
        prm = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prm = false;
                break;
            }
        }

        if (prm)
        {
            p_count++;
            cout << "\t" << i << ", ";
            if (p_count % 10 == 0)
            {
                cout << endl;
            }
        }
    }

    cout << "\n\t==============================================================================" << endl;
    cout << "\tThere are " << p_count << " prime numbers between " << num_low << " and " << num_high << endl;
    cout << "\t==============================================================================" << endl;

    return 0;
}