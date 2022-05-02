#pragma once

typedef unsigned long long ull;


template<int n>
struct Factorial
{
    //Use recursive to calculate the answer to factorial n.
    constexpr ull operator()() const { return Factorial<n - 1>()() * n; }
};

//The way to end the recursive loop.
template<>
struct Factorial<0>
{
    constexpr ull operator()() const { return 1; }
};
