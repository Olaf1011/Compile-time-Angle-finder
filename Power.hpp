#pragma once


template<int x, int power>
struct Pow
{
	//Use recursive to calculate the answer to x^y
	static constexpr unsigned long long value = x * Pow<x, power - 1>::value;
};

template<long double x, int power>
struct PowD
{
	//Use recursive to calculate the answer to x^y
	static constexpr long double value = x * PowD<x, power - 1>::value;
};

//The way to end the recursive loop.
template<int x>
struct Pow<x, 0>
{
	static constexpr unsigned long long  value = 1;
};

//The way to end the recursive loop.
template<long double x>
struct PowD<x, 0>
{
	static constexpr long double value = 1.0;
};

#define POW(x, y) Pow<x, y>::value
#define POWD(x, y) PowD<x, y>::value