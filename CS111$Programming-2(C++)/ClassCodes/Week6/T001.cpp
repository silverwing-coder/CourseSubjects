#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template<typename T=int>
T add(T a, T b){
    return a + b;
}

template<class T=int>
class Temp{
private:
    T dt1;
    T dt2;
public:
    Temp(){
        dt1 = 2.3;
        dt2 = 3.4;
    }

    T add(){
        return dt1 + dt2;
    }
};

int main()
{

    // Temp<> tmpA;
    // cout <<"default(int): " << tmpA.add() << endl;
    // Temp<float> tmpB;
    // cout << "float: " << tmpB.add() << endl;

    // int a = 3, b = 4;
    // cout << a + b;
    float a = 2.3, b = 3.4;
    cout << a + b;

    return 0;
}