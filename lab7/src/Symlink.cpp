#include "Symlink.h"
#include <iostream>

Symlink::Symlink(){}

Symlink::Symlink(const string& str, File* ptr): Base(str), link(ptr){}

Symlink::Symlink(const Symlink& other): Base(other.name), link(other.link)
{
}

void Symlink::print(int n) const
{
    Base::print(n);
    cout << " -> " << link->name << endl;
}
Symlink::~Symlink()
{
    delete link;
}