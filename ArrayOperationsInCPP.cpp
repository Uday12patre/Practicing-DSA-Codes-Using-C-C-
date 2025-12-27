#include<iostream>
using namespace std;

template <class T>
class Array
{
    private:
        T *A;
        int size;
        int length;
    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new T[size];
        }
        
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new T[size];
        }
        
        ~Array()
        {
            delete []A;
        }
        
        void display();
        void append(T x);
        void insert(int index, T x);
        void del(int index);
};

template<class T>
void Array<T>::display()
{
    cout << "Array is: ";
    for(int i = 0; i < length; i++)
    {
        cout << A[i] <<"\t";
    }
}

template<class T>
void Array<T>::append(T x)
{
    A[length++] = x;
}

template<class T>
void Array<T>::insert(int index, T x)
{
    if(index < size && index >= 0)
    {
        for(int i = length - 1; i >= index; i--)
        {
            A[i+1] = A[i];
        }
        
        A[index] = x;
        length++;
    }
}

template<class T>
void Array<T>::del(int index)
{
    if(index < length && index >= 0)
    {
        for(int i = index; i < length - 1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
    }
}

int main()
{
    Array<float> arr;
    arr.append(10.9);
    arr.append(20.5);
    arr.append(30.8);
    arr.append(40.5);
    
    arr.display();
    cout << endl;
    
    arr.insert(4,50.3);
    arr.insert(5,60.5);
    arr.insert(6,70.3);
    
    arr.display();
    cout << endl;
    
    arr.del(3);
    
    arr.display();
    cout << endl;
    
    arr.del(4);
    
    arr.display();
    cout << endl;
    
    arr.del(0);
    
    arr.display();
    cout << endl;
    
    return 0;
}
