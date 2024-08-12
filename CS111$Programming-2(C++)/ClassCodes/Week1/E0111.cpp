#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    int lo_num, hi_num, gcd;

    if (stoi(argv[1]) >= stoi(argv[2]))
    {
        lo_num = stoi(argv[2]);
        hi_num = stoi(argv[1]);
    }
    else
    {
        lo_num = stoi(argv[1]);
        hi_num = stoi(argv[2]);
    }

    for (int i = 1; i <= lo_num; i++)
    {
        if ((lo_num % i == 0) && (hi_num % i == 0))
        {
            gcd = i;
        }
    }

    cout << "The GCD of " << argv[1] << " and " << argv[2] << " is " << gcd << "." << endl;

    return 0;
}
