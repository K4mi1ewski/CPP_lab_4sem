#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "sum.h"

using namespace std;

class Data
{
    public:
    Data(const string& name, initializer_list<double> l): day(name), data(l){}
    void print() const;
    double at (int index) const {return data.at(index);}
    size_t datasize() {return data.size();}
    private:
    string day;
    vector<double> data;

    friend Sum sumData(const Data& d);
  
};