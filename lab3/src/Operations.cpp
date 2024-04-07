#include "Operations.h"
#include "Text.h"
Operations::Append::Append(const string& str): txt_(str) {}
Operations::Insert::Insert(const string& str): txt_(str){}
Operations::Replace::Replace(const string& str): txt_ (str){}

const Text Operations::Append::operator()(const Text& t) const
{
    const Text lol = txt_+t;
    return lol;
}

const Text Operations::Insert::operator()(const Text& t) const
{
   const Text lol = t+txt_;
   return lol;  
}

const Text Operations::Replace::operator()(const Text& t) const
{
    return txt_;
}