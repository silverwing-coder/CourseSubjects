#ifndef E0304POLY_H
#define E0304POLY_H
#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;
    int coordinates[2];

public:
    Circle()
    {
        // radius = (rand() % 4) + 2;
        radius = (rand() % 4);
        coordinates[0] = (rand() % 20) - 10;
        coordinates[1] = (rand() % 20) - 10;
        // coordinates[0] = (rand() % 20);
        // coordinates[1] = (rand() % 20);
    }

    int getRadius()
    {
        return radius;
    }

    int *getCoordinates()
    {
        return coordinates;
    }
};

class Rectangle
{
private:
    int width;
    int height;
    int coordinates[2];

public:
    Rectangle()
    {
        // width = (rand() % 4) + 2;
        // height = (rand() % 4) + 2;
        width = (rand() % 4);
        height = (rand() % 4);
        coordinates[0] = (rand() % 20) - 10;
        coordinates[1] = (rand() % 20) - 10;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    int *getCoordinates()
    {
        return coordinates;
    }
};

#endif