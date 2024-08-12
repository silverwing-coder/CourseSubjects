#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float radius)
    {
        this->radius = radius;
    }
    float getArea(float radius)
    {
        return this->radius * this->radius * 3.14159;
    }
};

int main()
{

    Circle circle(10);
    cout << circle.getArea(5) << endl;

    return 0;
}
