#include "Dir.h"
#include "File.h"
#include "Symlink.h"
#include <iostream>
#include <utility>
Dir::Dir(){}

Dir::Dir(const string& n): Base(n){}

Dir::Dir(const Dir& other): Base(other.name)
{
    for (auto el: other.lista)
    {
        if (auto ptr = dynamic_cast<File*>(el))
            lista.push_back(new File(*dynamic_cast<File*>(el)));
        else if (auto ptr = dynamic_cast<Symlink*>(el))
            lista.push_back(new Symlink(*dynamic_cast<Symlink*>(el)));
        else if (auto ptr = dynamic_cast<Dir*>(el))
            lista.push_back(new Dir(*dynamic_cast<Dir*>(el)));
    }
}

Dir& Dir::operator+= (Base* ptr)
{
    lista.push_back(ptr);
    return *this;
}

void Dir::print(int n) const
{
    Base::print(n);
    cout << " (dir)" << endl;
    for (auto el: lista)
        {
            el->print(n+1);
        }
}

Dir::~Dir()
{
    Dir* dirptr = nullptr;
    for (auto el: lista)
    {
       if (dirptr = dynamic_cast<Dir*>(el))
            dirptr->~Dir();
       delete el;
    }
}

void Dir::copy(Base* ptr)
{
    Base* pointer = nullptr;
    if (auto temp = dynamic_cast<File*>(ptr))
        pointer = new File (*temp);
    else if (auto temp = dynamic_cast<Symlink*>(ptr))
        pointer = new Symlink(*temp);
    else if (auto temp = dynamic_cast<Dir*>(ptr))
        pointer = new Dir(*temp);

    if (pointer)
        lista.push_back(pointer);
}

Dir* Dir::getDir(const string& str)
{
    Dir* dirptr = nullptr;
    for (auto el: lista)
    {
        if ((el->check(str)) && (dirptr = dynamic_cast<Dir*>(el)))
            return dirptr;
        else if ((dirptr = dynamic_cast<Dir*>(el)))
        {
            dirptr = dirptr->getDir(str);
            if(dirptr)
                return dirptr;
        }
    }
    return dirptr;
}

Base* Dir::get(const string& str)
{
    Base* ptr = nullptr;
    Dir* dirptr = nullptr;
    for(auto el: lista)
    {
        if (el->check(str))
            ptr = el;
        else if ((dirptr = dynamic_cast<Dir*>(el)))
            ptr = dirptr->get(str);
        if (ptr)
            return ptr;
    }
    return ptr;
}

void printFiles(Dir* directory)
{
    Dir* dirptr = nullptr;
    for (auto el: directory->lista)
    {
        if (auto ptr = dynamic_cast<File*>(el))
        {
            el->Base::print();
        }
        else if (auto ptr = dynamic_cast<Symlink*>(el))
        {
            el->Base::print();
        }
        else if (dirptr = dynamic_cast<Dir*>(el))
        {
         printFiles(dirptr);
        }
    }
}

ostream& operator<< (ostream&os, const Dir& obj)
{
    obj.print();
    return os;
}