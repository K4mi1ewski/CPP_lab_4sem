#pragma once

#include "File.h"

class Symlink: public Base
{
    public:
        Symlink();
        Symlink(const string& str, File* ptr);
        Symlink(const Symlink& other);
        void print(int n=0) const override;
        ~Symlink();
    private:
        File* link;
};