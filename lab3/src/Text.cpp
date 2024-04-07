#include "Text.h"
ostream& operator<<(ostream& os, const Text& obj)
{
    os << obj.txt;
    return os;
}
Text::Text (const string& str): txt(str){}
Text::Text(){}
Text Text::operator++(int)
{
    Text tmp(txt);
    txt = txt+txt;
    return tmp;
}
Text& Text::operator++()
{
    txt = txt+txt;
    return *this;   
}

const Text Text::operator+(const Text& obj)const
{
    Text tmp;
    tmp.txt = obj.txt + txt;
    return tmp;
}
//string Text::getText() const
//{
//    return txt;
//}