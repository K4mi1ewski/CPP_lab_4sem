#include "Base.h"
#include <iostream>
Base::Base()
{}

Base::Base(const string& n): name(n)
{}

void Base::print(int n) const
{
    for(int i=0;i<n;i++)
        cout << " ";
    cout << name << " ";
}
bool Base::check(const string& str)
{
    return (name==str);
}
