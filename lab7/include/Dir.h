#pragma once
#include "Base.h"


class Dir: public Base
{
    public:
        Dir();
        Dir(const string& n);
        Dir(const Dir& other);
        Dir& operator+= (Base* ptr);
        void print(int n=0) const override;
        void copy(Base* ptr);
        Dir* getDir(const string& str);
        Base* get (const string& str);
        ~Dir();
    private:
        vector<Base*> lista;
        friend void printFiles(Dir*);

    friend ostream& operator<< (ostream& os, const Dir& obj);
};

void printFiles(Dir* directory);