#include "table.h"
#include <algorithm>
void Table::print() const
{
    for (auto& el: table_)
    {
        el.print();
    }
}

Table& Table::sort(int index)
{
    for (auto& el: table_)
    {
        if (el.datasize()<= index)
        {
            cout << "Indeks " << index << " nieprawidlowy! "<<endl;
            return *this;
        }
    }

    std::sort(table_.begin(),table_.end(), [&index](const Data& d1, const Data& d2){return (d1.at(index) < d2.at(index));});
    return *this;
}

Table& Table::sortBy(function<bool(const Data& d1, const Data& d2)> f)
{
    std::sort(table_.begin(),table_.end(),f);
    return *this;
}