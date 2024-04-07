#pragma once
#include <vector>
#include <functional>
#include "Text.h"
#include "Operations.h"
using namespace std;
class TextManipulator
{
    public:
        void insert(function<Text(const Text& t)> functor);
        void clear();
        const Text manipulate(const Text& t) const;

    private:
        vector<function<Text(const Text& t)>> list;
};
