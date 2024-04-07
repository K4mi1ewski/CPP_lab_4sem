#pragma once
#include <string>
#include "Text.h"
using namespace std;

namespace Operations
{
    class Append{
        public:
        const Text operator()(const Text& t)const ;
        Append(const string& str);
        private:
        Text txt_;
    };

    class Insert{
        public:
        const Text operator()(const Text& t)const;
        Insert (const string& str);
        private:
        Text txt_;
    };

    class Replace{
        public:
        const Text operator()(const Text& t)const;
        Replace(const string& str);
        private:
        Text txt_;
    };
};