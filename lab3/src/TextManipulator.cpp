#include "TextManipulator.h"
void TextManipulator::insert (function<Text(const Text& t)> functor)
{
    list.push_back(functor);
}
void TextManipulator::clear()
{
    list.clear();
}
const Text TextManipulator::manipulate(const Text& t) const
{
    Text tmp(t);
    for (auto el: list)
    {
        tmp = el(tmp);
    }
    return tmp;
}