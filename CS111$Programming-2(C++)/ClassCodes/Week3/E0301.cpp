#include <iostream>
using namespace std;

class Rectangle {
    private:
        float width;
        float length;

    public:
        Rectangle(){};
        // Rectangle(float width = 10.0, float length = 10.0){
        //     width = width;
        //     length = length;
        // }

        void setData(float width, float length){
            width = width;
            length = length;
        }
        void setWidth(float width){
            width = width;
        }
        void setLength(float length){
            length = length;
        }

        float getWidth(){
            return width;
        }
        float getLength(){
            return length;
        }
        float getArea(){
            return width * length;
        }
};

int main(){

    Rectangle box1;
    box1.setData(10.0, 11.0);

    cout << box1.getArea() << endl;

    return 0;
}