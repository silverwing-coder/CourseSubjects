#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    T *elements;
    int stack_size; // stack size
    int array_size; // array size

public:
    Stack()
    {
        stack_size = 0;
        array_size = 3; // initialize smallest(default) array size
        elements = new T[array_size];
        for (int i = 0; i < array_size; i++)
        {
            *(elements + i) = 0;
        }
    };
    ~Stack()
    {
        delete elements;
    };

    bool empty()
    {
        if (stack_size == 0)
            return true;
        else
            return false;
    }

    T peek()
    {
        return *(elements + (stack_size - 1));
    }

    void push(T elmt)
    {

        *(elements + stack_size) = elmt;
        stack_size += 1;

        if (stack_size >= array_size)
        {
            T *temp_elements = elements;

            array_size *= 2;
            elements = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                *(elements + i) = 0;
            }
            // deep copy of elements
            for (int i = 0; i < stack_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "Array size doubled to " << array_size << endl;
        }
    }

    T pop()
    {

        if (stack_size <= (array_size / 2) && stack_size >= 3) // 3 : minumum array size
        {
            T *temp_elements = elements;

            array_size = stack_size;
            elements = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                *(elements + i) = 0;
            }

            // deep copy of elements
            for (int i = 0; i < stack_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "\nArray size halfed to " << array_size << endl;
        }

        stack_size -= 1;
        return *(elements + stack_size);
    }

    int getSize()
    {
        return stack_size;
    }

    // T at(int idx)
    // {
    //     return *(elements + idx);
    // }

    T operator[](int idx)
    {
        return *(elements + idx);
    }
};

int main()
{

    Stack<int> intStack;
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i * 2);
    }

    cout << "Integer Stack by [] index operator : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intStack[i] << ", ";
    }
    cout << endl;

    // cout << "Integer Stack: " << endl;
    // while (!intStack.empty())
    // {
    //     cout << intStack.pop() << ", ";
    // }
    // cout << endl;

    // Stack<string> strStack;
    // strStack.push("Winston-Salem");
    // strStack.push("Greensboro");
    // strStack.push("Pilot-City");

    // cout << "String Stack: " << endl;
    // while (!strStack.empty())
    // {
    //     cout << strStack.pop() << ", ";
    // }
    // cout << endl;

    return 0;
}