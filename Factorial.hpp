#pragma once

typedef unsigned long long ull;


template<int n>
struct Factorial
{
    //Use recursive to calculate the answer to factorial n.
    static constexpr ull value = Factorial<n - 1>::value * n;
};

//The way to end the recursive loop.
template<>
struct Factorial<0>
{
    static constexpr ull value = 1;
};

#define FACTORIAL(x) Factorial<x>::value
