#include "assoc.h"

ostream& operator<< (ostream& os, const TAssoc& obj)
{
    for (auto el: obj.tab)
    {
        os << "--- klucz: " << el.label << " wartosc: " << el.price << endl;
    }
    return os;
}

TAssoc& TAssoc::insert (const string& lbl, double val)
{
    tab.push_back({lbl, val});
    return *this;
}

double& TAssoc::operator[](const string& lbl) 
{
    for (auto& el: tab)
    {
        if (el.label == lbl)
            return el.price;
    }
    tab.push_back({lbl,0});
    return tab[(tab.size()-1)].price;
}

const double TAssoc::operator[](const string& lbl) const
{
    for (auto& el: tab)
    {
        if (el.label == lbl)
            return el.price;
    }
    return 0;
}

ostream& operator<< (ostream& os, const assoc& obj)
{
    os << "--- klucz:" << obj.label << " wartosc: " << obj.price << endl;
    return os;
}

assoc& TAssoc::operator[] (int num)
{
    if (num < tab.size())
        return tab[num];
    else
        return tab[tab.size()-1];
}

double TAssoc::sum() const
{
    double sum = 0;
    for (auto& el: tab)
    {
        sum+=el.price;
    }   
    return sum;
}

bool TAssoc::contains(const string lbl) const
{
    for (auto& el: tab)
    {
        if(el.label == lbl)
            return true;
    }
    return false;
}

TAssoc& TAssoc::operator= (TAssoc&& other)
{
    if (this!=&other)
        tab = move(other.tab);    
    return *this;   
}

TAssoc& TAssoc::operator= (const TAssoc& other)
{   if (this!=&other)
        tab = other.tab;   
    return *this;
}
TAssoc::~TAssoc(){}
TAssoc::TAssoc(){}
TAssoc::TAssoc(const TAssoc& other): tab(other.tab) {}