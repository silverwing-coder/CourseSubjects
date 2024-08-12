#ifndef E0301_H
#define E0301_H

class Rectangle {
    private:
        float width;
        float length;

    public:
        Rectangle(){};
        Rectangle(float widthA, float lengthA){
            width = widthA;
            length = lengthA;
        }

        void setData(float widthA, float lengthA){
            width = widthA;
            length = lengthA;
        }
        void setWidth(float widthA){
            width = widthA;
        }
        void setLength(float lengthA){
            length = lengthA;
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

#endif