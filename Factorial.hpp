#pragma once

typedef unsigned long long ull;


template<int n>
struct Factorial
{
    static constexpr ull value = Factorial<n - 1>::value * n;
    constexpr ull operator()() const { return value; }
    constexpr operator double() const { return  value; }

};

template<>
struct Factorial<0>
{
    static constexpr ull value = 1;
};
