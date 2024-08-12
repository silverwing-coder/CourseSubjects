#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector
{
private:
    T *elements;
    int vector_size; // Vector size
    int array_size;  // array size

public:
    Vector()
    {
        vector_size = 0;
        array_size = 3; // initialize smallest(default) array size
        elements = new T[array_size];
        // for (int i = 0; i < array_size; i++)
        // {
        //     *(elements + i) = 0;
        // }
    };
    ~Vector()
    {
        delete elements;
    };

    bool empty()
    {
        if (vector_size == 0)
            return true;
        else
            return false;
    }

    T at(int idx)
    {
        return *(elements + idx);
    }

    void push_back(T elmt)
    {

        *(elements + vector_size) = elmt;
        vector_size += 1;

        if (vector_size >= array_size)
        {
            T *temp_elements = elements;

            array_size *= 2;
            elements = new T[array_size];
            // for (int i = 0; i < array_size; i++)
            // {
            //     *(elements + i) = 0;
            // }
            // deep copy of elements
            for (int i = 0; i < vector_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "Array size doubled to " << array_size << endl;
        }
    }

    T pop_back()
    {

        if (vector_size <= (array_size / 2) && vector_size >= 3) // 3 : minumum array size
        {
            T *temp_elements = elements;

            array_size = vector_size;
            elements = new T[array_size];
            // for (int i = 0; i < array_size; i++)
            // {
            //     *(elements + i) = 0;
            // }

            // deep copy of elements
            for (int i = 0; i < vector_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "\nArray size halfed to " << array_size << endl;
        }

        vector_size -= 1;
        T ret_value = *(elements + vector_size);
        *(elements + vector_size) = 0;
        return ret_value;
    }

    int getSize()
    {
        return vector_size;
    }

    void push_at(int idx, T elmt)
    {
        for (int i = vector_size; i > idx; i--)
        {
            *(elements + i) = *(elements + i - 1);
        }

        *(elements + idx) = elmt;
        vector_size += 1;

        if (vector_size >= array_size)
        {
            T *temp_elements = elements;

            array_size *= 2;
            elements = new T[array_size];
            // for (int i = 0; i < array_size; i++)
            // {
            //     *(elements + i) = 0;
            // }
            // deep copy of elements
            for (int i = 0; i < vector_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "Array size doubled to " << array_size << endl;
        }
    }

    T pop_at(int idx)
    {

        if (vector_size <= (array_size / 2) && vector_size >= 3) // 3 : minumum array size
        {
            T *temp_elements = elements;

            array_size = vector_size;
            elements = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                *(elements + i) = 0;
            }

            // deep copy of elements
            for (int i = 0; i < vector_size; i++)
            {
                *(elements + i) = *(temp_elements + i);
            }
            delete temp_elements;
            // cout << "\nArray size halfed to " << array_size << endl;
        }

        T ret_value = *(elements + idx);
        for (int i = idx; i < vector_size; i++)
        {
            *(elements + i) = *(elements + i + 1);
        }

        vector_size -= 1;
        *(elements + vector_size) = 0;

        return ret_value;
    }
};

int main()
{

    Vector<int> intVector;
    for (int i = 0; i < 10; i++)
    {
        intVector.push_back(i * 2);
    }

    cout << "\nBefore pop_at(): " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intVector.at(i) << ", ";
    }
    cout << endl;

    cout << "pop_at(3): " << intVector.pop_at(3) << endl;
    cout << "After pop_at(): " << endl;
    for (int i = 0; i < intVector.getSize(); i++)
    {
        cout << intVector.at(i) << ", ";
    }
    cout << endl;
    // while (!intVector.empty())
    // {
    //     cout << intVector.pop_back() << ", ";
    // }
    // cout << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     intVector.push_back(i * 2);
    // }

    cout << "\nBefore push_at(): " << endl;
    for (int i = 0; i < intVector.getSize(); i++)
    {
        cout << intVector.at(i) << ", ";
    }
    cout << endl;

    cout << "push_at(3, 5): " << endl;
    intVector.push_at(3, 5);
    cout << "After push_at(): " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intVector.at(i) << ", ";
    }
    cout << endl;
    // while (!intVector.empty())
    // {
    //     cout << intVector.pop_back() << ", ";
    // }
    cout << endl;

    // Vector<string> strVector;
    // strVector.push_back("Winston-Salem");
    // strVector.push_back("Greensboro");
    // strVector.push_back("Pilot-City");

    // cout << "String Vector: " << endl;
    // while (!strVector.empty())
    // {
    //     cout << strVector.pop_back() << ", ";
    // }
    // cout << endl;

    return 0;
}