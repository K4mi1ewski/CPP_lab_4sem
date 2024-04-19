#pragma once
#include "Base.h"


class File: public Base
{
    public:
        File();
        File(const string& str, int val);
        File (const File& other);
        void rename(const string& str);
        void print(int n=0) const override;
        friend class Symlink;
    private:
        int size;
};
