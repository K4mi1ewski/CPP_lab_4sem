#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <string>
using namespace std;
class MyArray
{
    int* array;
    size_t maxsize;
    

    public:
    MyArray(int n);
    void print (const string& str) const;
    int size();
    int& operator[](int num);
    const int& operator[](int num) const;
    friend ostream& operator<< (ostream& os, const MyArray& arr);
    MyArray& operator++();
    MyArray(const MyArray& obj);
    MyArray& operator= (const MyArray& other);
    MyArray& operator= (MyArray&& other);
    ~MyArray();
};


#endif