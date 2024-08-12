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

    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
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
    GeometricObject *p = &obj;
    /** No cast */
    // cout << "The radius is " << obj.getRadius() << endl;
    // cout << "The diameter is " << obj.getDiameter() << endl;

    // cout << "The width is " << obj.getWidth() << endl;
    // cout << "The height is " << obj.getHeight() << endl;

    // cout << "The area is " << obj.getArea() << endl;
    // cout << "The perimeter is " << obj.getPerimeter() << endl;

    /** Static cast */
    // cout << "The radius is " << static_cast<Circle *>(p)->getRadius() << endl;
    // cout << "The diameter is " << static_cast<Circle *>(p)->getDiameter() << endl;

    // cout << "The width is " << static_cast<Rectangle *>(p)->getWidth() << endl;
    // cout << "The height is " << static_cast<Rectangle *>(p)->getHeight() << endl;

    // cout << "The area is " << obj.getArea() << endl;
    // cout << "The perimeter is " << obj.getPerimeter() << endl;

    /** Dynamic cast */

    cout << "The area is " << obj.getArea() << endl;
    cout << "The perimeter is " << obj.getPerimeter() << endl;

    Circle *pc = dynamic_cast<Circle *>(p);
    Rectangle *pr = dynamic_cast<Rectangle *>(p);
    if (pc != NULL)
    {
        cout << "The radius is " << pc->getRadius() << endl;
        cout << "The diameter is " << pc->getDiameter() << endl;
    }

    if (pr != NULL)
    {
        cout << "The width is " << pr->getWidth() << endl;
        cout << "The height is " << pr->getHeight() << endl;
    }
}

int main()
{
    /** Static cast*/
    // Rectangle rectangle(10.0, 11.0, "blue", true);
    // GeometricObject *p = &rectangle;
    // displayGeometricObject(rectangle);

    // Circle circle(10.0, "green", true);
    // GeometricObject *p = &circle;
    // displayGeometricObject(circle);

    /** Dynamic Cast*/

    Rectangle rectangle(10, 11);
    GeometricObject *p = &rectangle;
    Circle *pc = dynamic_cast<Circle *>(p);
    cout << (*pc).getRadius() << endl;

    // Circle circle(10);
    // Rectangle rectangle(10, 11);
    // cout << "circle: ";
    // displayGeometricObject(circle);
    // cout << "rectanble: ";
    // displayGeometricObject(rectangle);

    return 0;
}
