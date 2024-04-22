#include "Data.h"

Fraction::Fraction(int n, int d): nominator(n), denominator(d)
{}

StringData::StringData(const string& str): text(str){}

void Fraction::print() const
{
    if (denominator!=1)
    {
        cout << nominator << "/" << denominator;
    }
    else
        cout << nominator;
}

void StringData::print() const
{
    cout << "\"" << text << "\"";
}

Fraction* Fraction::clone() const
{
    Fraction* cloned = new Fraction (this->nominator, this->denominator);
    return cloned;
}

StringData* StringData::clone() const
{
    StringData* cloned = new StringData (this->text);
    return cloned;
}

CharData::CharData(const char znak): sign(znak)
{
}

void CharData::print() const
{
    cout << "'" << sign << "'";
}

CharData* CharData::clone() const
{
    CharData* cloned = new CharData(this->sign);
    return cloned;
}

double Fraction::eval() const
{
    return (static_cast<double>(nominator)/denominator);
}

double StringData::eval() const
{
    return static_cast<double> (text.length());
}

double CharData::eval() const
{
    return static_cast<double> (sign);
}