#include <iostream>
#include "E0301Class.h"
using namespace std;

// class Rectangle {
//     private:
//         float width;
//         float length;

//     public:
//         Rectangle(){};
//         Rectangle(float widthA, float lengthA){
//             width = widthA;
//             length = lengthA;
//         }

//         void setData(float widthA, float lengthA){
//             width = widthA;
//             length = lengthA;
//         }
//         void setWidth(float widthA){
//             width = widthA;
//         }
//         void setLength(float lengthA){
//             length = lengthA;
//         }

//         float getWidth(){
//             return width;
//         }
//         float getLength(){
//             return length;
//         }
//         float getArea(){
//             return width * length;
//         }
// };

int main(){

    Rectangle box1;
    box1.setData(10.0, 11.0);

    cout << "=======================================" << endl;
    cout << "Width is " << box1.getWidth() << endl;
    cout << "Length is " << box1.getLength() << endl;

    cout << "Area is " << box1.getArea() << endl;
    cout << "=======================================" << endl;

    return 0;
}