// #ifndef GEOMETRIC_H
// #define GEOMETRIC_H

#include <iostream>
#include <typeinfo>
using namespace std;

class GeometricObject
{
    // private:
protected:
    string color;
    bool filled;

public:
    GeometricObject()
    {
        color = "white";
        filled = true;
    }
    GeometricObject(string ncolor, bool nfilled)
    {
        color = ncolor;
        filled = nfilled;
    }

    string getColor()
    {
        return color;
    }
    void setColor(string nclolr)
    {
        color = nclolr;
    }

    bool isFilled()
    {
        return filled;
    }

    void setFilled(bool nfilled)
    {
        filled = nfilled;
    }

    virtual string toString()
    {
        return ("This is GeometricObject.");
    }
};

class Circle : public GeometricObject
{
private:
    double radius;

public:
    Circle()
    {
        radius = 0;
    }

    Circle(double nradius)
    {
        radius = nradius;
    }

    Circle(double nradius, string ncolor, bool nfilled)
    {
        radius = nradius;
        color = ncolor;
        filled = nfilled;
    }

    double getRadius()
    {
        return radius;
    }
    void setRadius(double nradius)
    {
        radius = nradius;
    }

    double getArea()
    {
        return radius * radius * 3.14159;
    }

    double getPerimeter()
    {
        return 2 * radius * 3.14159;
    }

    double getDiameter()
    {
        return 2 * radius;
    }

    string toString()
    {
        return ("This is Circle Object");
    }
};

class Rectangle : public GeometricObject
{
private:
    double width;
    double height;

public:
    Rectangle()
    {
        width = 0;
        height = 0;
    }
    Rectangle(double nwidth, double nheight)
    {
        width = nwidth;
        height = nheight;
    }
    Rectangle(double nwidth, double nheight, string ncolor, bool nfilled)
    {
        width = nwidth;
        height = nheight;
        color = ncolor;
        filled = nfilled;
    }

    double getWidth()
    {
        return width;
    }
    void setWidth(double nwidth)
    {
        width = nwidth;
    }
    double getHeight()
    {
        return height;
    }
    void setHeight(double nheight)
    {
        height = nheight;
    }

    double getArea()
    {
        return width * height;
    }

    double getPerimeter()
    {
        return 2 * (width + height);
    }

    string toString()
    {
        return ("This is Rectangle Object");
    }
};

// #endif

void displayGeometricObject(GeometricObject &obj)
{
    cout << obj.toString() << endl;
}

int main()
{

    // Circle circle(10.0, "green", true);
    // cout << "Area of circle: " << circle.getArea() << endl;

    // Rectangle rectangle(10.0, 11.0, "blue", true);
    // cout << "Area of rectangle: " << rectangle.getArea() << endl;

    /** Function override */
    // cout << "[Function overide] circle.GeometrictObject.toString(): " << circle.GeometricObject::toString() << endl;

    /** typeid() operator */
    // cout << "typeid: " << typeid(circle).name() << endl;

    /** Polymorphism */
    // GeometricObject obj;
    // displayGeometricObject(obj);
    // cout << obj.toString() << endl;
    // displayGeometricObject(circle);
    // cout << circle.toString() << endl;
    // displayGeometricObject(rectangle);
    // cout << rectangle.toString() << endl;

    /** Static casting */

    /** Dynamic casting */

    return 0;
}
