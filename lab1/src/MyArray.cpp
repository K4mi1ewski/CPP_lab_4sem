#include "MyArray.h"

MyArray::MyArray(int n)
{
    cout << "Konstruktor jednoargumentowy!" <<endl;
    array = new int [n];
    maxsize = n;
    for (int i = 0; i<maxsize;i++)
    {
        array[i]=0;
    }
}
void MyArray::print(const string& str) const
{
    cout << str << " = [";
    for (int i = 0; i<MyArray::maxsize;i++)
    {
        cout << array[i] <<", ";
    }
    cout << "]"<<endl;
}

int MyArray::size()
{
    return maxsize;
}

int& MyArray::operator[](int num)
{
    if (num<maxsize)
        return array[num];
    else
        return array[maxsize-1];
}

const int& MyArray::operator[](int num) const
{
    if (num<maxsize)
        return array[num];
    else
        return array[maxsize-1];
}
ostream& operator<< (ostream& os,  MyArray& arr)
{   
    os << "[";
    for (int i = 0; i<arr.size(); i++)
    {
        os << arr.array[i] <<", ";
    }
    os << "]" << endl;
    return os;
}

MyArray& operator++()
{
    for (int i = 0; i<maxsize;i++)
    {
        array[i]++;
    }
    return *this;
}

MyArray(const MyArray& obj)
{   
    cout<<"Konstruktor kopiujacy!"<<endl;
    maxsize = obj.maxsize;
    array = new int [maxsize];
    for (int i = 0; i<maxsize; i++)
    {
        array[i] = obj.array[i];
    }
}

MyArray& operator= (const MyArray& other)
{
    maxsize = other.maxsize;
    delete[]array;
    array = new int[maxsize];
    for (int i = 0; i<maxsize;i++)
    {
        array[i] = other.array[i];
    }
}

MyArray& operator= (MyArray&& other)
{
    if (this!=&other)
    {
        delete[]array;
        maxsize = exchange(other.maxsize, 0);
        array = move(other.array);
    }
    
    return *this;
}

MyArray::~MyArray()
{   
    cout << "Usuwam tablice"<<endl;
    delete[] array;
}