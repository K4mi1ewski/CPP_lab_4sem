#pragma once
#include "data.h"
#include <functional>

class Table
{
    public:
    void operator+=(const Data& d) {table_.push_back(d);}
    void print() const;
    Table& sort(int index);
    Table& sortBy(function<bool(const Data& d1, const Data& d2)> f);
    private:
    vector<Data> table_;
};