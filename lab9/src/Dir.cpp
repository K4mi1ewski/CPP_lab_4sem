#include "Dir.h"
#include "File.h"
#include "Symlink.h"
#include <iostream>
#include <utility>
#include <functional>
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
       //if (dirptr = dynamic_cast<Dir*>(el))
        //    dirptr->~Dir();
       
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

void Dir::operator-=(const string& name)
{
    for (int i = 0; i<lista.size();i++)
    {
        if (lista[i]->getname() == name)
                {delete(lista[i]);
                lista.erase(lista.begin()+i);
                }
    }
}

void Dir::printFilesGreaterThanSize(int size)
{
    std::function<void(Dir*)> my_print = [&](Dir* dirptr){
        for (auto el: dirptr->lista)
        {
            File* fileptr = dynamic_cast<File*>(el);
            if (fileptr&& fileptr->getSize()>size)
            {
                fileptr->print();
            }
            if (Dir* dirptr = dynamic_cast<Dir*>(el))
                my_print(static_cast<Dir*>(el));
        }
    };
    my_print(this);
}

void Dir::printByType(FSType type, int maxdeep, int deep, const string& str)
{
    if(deep > maxdeep) 
        return;
    
    auto my_lambda = [&](){string path;
    if (str=="")
        path = getname();
    else
        path = str+"/"+getname();
    
    for (auto el: lista)
    {
        if (el->getType()==type)
        {
            el->display(path);
        }
        if (Dir* dirptr=dynamic_cast<Dir*>(el))
        {
            static_cast<Dir*>(el)->printByType(type,maxdeep,deep+1,path);
        }
    }};
    my_lambda();
}

void Dir::printDirs(int deep)
{
    printByType(FSType::Dir,deep);
}