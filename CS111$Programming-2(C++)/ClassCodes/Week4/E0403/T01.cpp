
#include <iostream>

using namespace std;

int main()
{
    string country;
    while (true)
    {
        cout << "Enter a country you want to visit : ";
        getline(cin, country);
        cout << "The country you want to visit is : " << country;

        if (country == "q")
        {
            break;
        }

        return 0;
    }
}