#include <iostream>
#include "E0304Poly.h"
#include "E0304Bubbles.h"
using namespace std;

int main()
{

    Bubbles bubbles;

    cout << "Overlapped Circles: " << bubbles.getOverlappedCircles() << endl;
    cout << "Overlapped Rectangles: " << bubbles.getOverlappedRectangles() << endl;

    return 0;
}