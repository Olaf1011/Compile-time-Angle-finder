#pragma once

typedef unsigned long long ull;
typedef long double ld;

template<int n>
struct Factorial
{
    static constexpr ull value = Factorial<n - 1>::value * n;
    constexpr ull operator()() { return value; }
    constexpr operator int() const { return  value; }
    constexpr operator double() const { return  value; }

};

template<>
struct Factorial<0>
{
    static constexpr ull value = 1;
};
