#pragma once

typedef long long ull;

template<int n>
struct Factorial
{
    static constexpr ull value = Factorial<n - 1>::value * n;
    constexpr ull operator()() { return Factorial<n - 1>::value * n; }
    constexpr operator int() const { return  Factorial<n - 1>::value * n; }
    constexpr operator double() const { return  Factorial<n - 1>::value * n; }

};

template<>
struct Factorial<0>
{
    static constexpr ull value = 1;
    constexpr ull operator()() { return 1; }
    constexpr operator int() const { return 1; }
    constexpr operator double() const { return 1; }
};
