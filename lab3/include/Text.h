#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Text
{
    public:
        friend ostream& operator<<(ostream& os, const Text& obj);
        Text();
        Text(const string& str);
        Text operator++(int);
        Text& operator++();
        const Text operator+(const Text& obj)const;
        //string getText()const;
    private:
        string txt;

};