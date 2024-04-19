#pragma once
#include <string>
#include <vector>

using namespace std;

class Base
{
  public:
    Base();
    Base(const string& n);
    
    virtual void print (int n = 0) const;
    bool check(const string& str);
  protected:
    string name;
};