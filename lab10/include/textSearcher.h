#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
class TextSearcher
{
public:
void loadTextFromFile (const string& name);
vector<int> multiThreadedSearch(const string& name, int count);
int countResults(vector<int>&vec) const;
void printResults(vector<int>&vec) const;
string& getText() {return txt;}
private:
string txt;

};