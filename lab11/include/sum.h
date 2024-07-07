#pragma once

class Sum
{
    public:
    Sum(double val): value_(val) {}
    double value() const {return value_;}
    void operator() (double val) {value_+=val;}
    private:
    double value_;
};