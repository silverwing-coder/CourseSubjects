#ifndef E0304BUBBLES_H
#define E0304BUBBLES_H
#include <iostream>
#include <math.h>
#include "E0304Poly.h"
using namespace std;

class Bubbles
{
private:
    Circle circles[30];
    Rectangle rectangles[30];

public:
    Bubbles()
    {
        for (int i = 0; i < 30; i++)
        {
            circles[i] = Circle();
            rectangles[i] = Rectangle();
        }
    }

    int getOverlappedCircles()
    {
        int num_overlap = 0;
        float sradius;
        float dist;
        for (int i = 0; i < 30; i++)
        {
            for (int j = i + 1; j < 30; j++)
            {
                sradius = (float)(circles[i].getRadius() + circles[j].getRadius());
                dist = (float)(pow(circles[i].getCoordinates()[0] - circles[j].getCoordinates()[0], 2) + pow(circles[i].getCoordinates()[1] - circles[j].getCoordinates()[1], 2));
                dist = sqrt(dist);

                if (sradius > dist)
                {
                    // cout << "circle: " << i << " and " << j << endl;
                    num_overlap++;
                }
            }
        }

        return num_overlap;
    }

    int getOverlappedRectangles()
    {
        int num_overlap = 0;
        float xdist, ydist;
        float swidth, sheight;
        for (int i = 0; i < 30; i++)
        {
            for (int j = i + 1; j < 30; j++)
            {
                if (rectangles[i].getCoordinates()[0] > rectangles[j].getCoordinates()[0])
                {
                    xdist = (float)(rectangles[i].getCoordinates()[0] - rectangles[j].getCoordinates()[0]);
                }
                else
                {
                    xdist = (float)(rectangles[j].getCoordinates()[0] - rectangles[i].getCoordinates()[0]);
                }

                if (rectangles[i].getCoordinates()[1] > rectangles[j].getCoordinates()[1])
                {
                    ydist = (float)(rectangles[i].getCoordinates()[1] - rectangles[j].getCoordinates()[1]);
                }
                else
                {
                    ydist = (float)(rectangles[j].getCoordinates()[1] - rectangles[i].getCoordinates()[1]);
                }

                swidth = ((float)rectangles[i].getWidth() + (float)rectangles[j].getWidth()) / 2;
                sheight = ((float)rectangles[i].getHeight() + (float)rectangles[j].getHeight()) / 2;

                if (xdist <= swidth && ydist <= sheight)
                {
                    // cout << "Rectangle: " << i << " and " << j << endl;
                    num_overlap++;
                }
            }
        }

        return num_overlap;
    }
};

//     int getOverlappedPolygons()
//     {
//         int num_overlap = 0;

//         return num_overlap;
//     }
// };

#endif