#include "data.h"
#include <numeric>
void Data::print() const
{
    cout << day << ": ";
    int manip = 4;
    for (auto el: data)
        cout << setw(manip++) << el << " ";
    cout <<endl;
}


Sum sumData(const Data& d)
{
    // for (auto el: d.data)
    //     cout << el << " ";
    double val = std::accumulate(d.data.begin(),d.data.end(),0.0);
    //cout << "val:"<<val;
    return Sum(val);
}