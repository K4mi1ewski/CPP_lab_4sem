#include "File.h"
#include <iostream>
File::File(): size(0) {}

File::File(const string& str, int val): Base(str), size(val){}

File::File(const File& other): Base(other.name), size(other.size){}

void File::rename(const string& str)
{
    name=str;
}

void File::print(int n) const
{
    Base::print(n);
    cout << "(" << size << ")" << endl;
}