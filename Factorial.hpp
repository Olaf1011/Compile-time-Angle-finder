#pragma once


template<int n>
struct Factorial
{
    static constexpr long long result = Factorial<n - 1>::result * n;
};
template<>
struct Factorial<1>
{
    static constexpr long long result = 1;
};

template<>
struct Factorial<0>
{
    static constexpr long long result = 0;
};