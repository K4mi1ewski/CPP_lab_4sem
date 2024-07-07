#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
namespace obj
{
template <typename T>
double srednia (const T tab[], int size)
{
    double sum = 0;
    for (int i = 0; i<size;i++)
    {
        sum+=tab[i];
    }
    return (sum/size);
}

template<typename T, size_t N>
double srednia (T (&tab) [N])
{
    double sum = 0;
    for (int i = 0; i<N; i++)
    {
        sum+=tab[i];
    }
    return (sum/N);
}

template <typename T>
T min (T tab[], size_t size)
{
return *std::min_element(tab, tab+size);
}

template <typename T>
T min (T t1, T t2)
{
    if (t1 < t2)
        return t1;
    else 
        return t2;
}

template <typename T>
T* min (T* t1, T* t2)
{
    if (*t1 < *t2)
        return t1;
    else
        return t2;
}

template <typename T, std::size_t size>
T min (T (&tab) [size])
{
   return *std::min_element(tab, tab+size);
}

template <typename T>
T max ( T tab[], size_t size)
{
  return *std::max_element(tab, tab+size);
}

template <typename T>
T max ( T t1, T t2)
{
    if (t1 > t2)
        return t1;
    else
        return t2;
}

template <typename T, std::size_t N>
T max (T (&tab) [N])
{
return *std::max_element(tab, tab+N);
}

std::string text (const bool& val)
{
    if (val)
        return "TRUE";
    else
        return "FALSE";
}

template <const std::size_t index1, const std::size_t index2, std::size_t N>
bool allPrime(const int (&tab)[N])
{
    if ((index1>index2) || (index2>N))
    {
        std::cout << "ERROR Nieprawidlowy zakres!" << std::endl;
        return false;
    }
    for (size_t i=index1;i<index2;i++)
    {
        for (int j = 2; j<tab[i];j++)
        {
            if (tab[i]%j == 0)
                return false;
        }
    }
    return true;
}

template<>
const char* max<const char*> (const char* s1, const char* s2)
{
    if (strcmp(s1,s2)>0)
        return s1;
    else
        return s2;
}

template<>
const char* min<const char*> (const char* s1, const char* s2)
{
    if (strcmp(s1,s2)<0)
        return s1;
    else
        return s2;
}

template<const std::size_t index1, const std::size_t index2>
const char* min (const char* t[],size_t size)
{
    size_t ind2 = index2;
    if (index2 > size)
        ind2=size;
    const char* result = t[index1];
    for (size_t i = index1+1;i<ind2;i++)
    {
        if (strcmp(result,t[i])>0)
        {
            result = t[i];
        }
    }
    return result;
}

template<const std::size_t index1, const std::size_t index2>
const char* max(const char* t[],size_t size)
{
    size_t ind2 = index2;
    if (index2 > size)
        ind2=size;
    const char* result = t[index1];
    for (size_t i = index1+1;i<ind2;i++)
    {
        if (strcmp(result,t[i])<0)
        {
            result = t[i];
        }
    }
    return result;
}
};