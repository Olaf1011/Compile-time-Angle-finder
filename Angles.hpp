#pragma once
#include <windows.h>
#include <array>
#include <iostream>
#include <string>
#include "Factorial.hpp"

constexpr double PI = 3.14159265;
class Sin;
class Cos;

template<double x, int power>
struct Pow
{
	static constexpr double value = x * Pow<x, power - 1>::value;
};

template<double x>
struct Pow<x, 0>
{
	static constexpr double value = 1.0;
};


template<int x, int power>
class Pow
{
	static constexpr int value = x * Pow<x, power - 1>::value;
};

template<int x>
class Pow<x, 0>
{
	static constexpr int value = 1;
};

template<int A, class Type>
class AngleFinder;

template<int X>
class AngleFinder<X, Sin>
{
	static constexpr double x = static_cast<double>(X) * PI / 180.0;
public:
	constexpr double operator()() const { return x -	(x * x * x) / Factorial<3>()() +
														(x * x * x * x * x) / Factorial<5>()() -
														(x * x * x * x * x * x * x) / Factorial<7>()() +
														(x * x * x * x * x * x * x * x * x) / Factorial<9>()() -
														(x * x * x * x * x * x * x * x * x * x * x) / Factorial<11>()() +
														(x * x * x * x * x * x * x * x * x * x * x * x * x) / Factorial<13>()(); }
};

template<int A>
class AngleFinder<A, Cos>
{
	static constexpr double x = static_cast<double>(A) * PI / 180.0;
public:
	double operator()() const { return	1.0 -	(x * x) / Factorial<2>()() +
												(x * x * x * x)/ Factorial<4>()() -
												(x * x * x * x * x * x)/ Factorial<6>()() +
												(x * x * x * x * x * x * x * x)/ Factorial<8>()() -
												(x * x * x * x * x * x * x * x * x * x) / Factorial<10>()() +
												(x * x * x * x * x * x * x * x * x * x * x * x) / Factorial<12>()() -
												(x * x * x * x * x * x * x * x * x * x * x * x * x * x) / Factorial<14>()(); }

};

template<>
class AngleFinder<0, Sin>
{
public:
	constexpr double operator()() const { return 0.0; }
};

template<>
class AngleFinder<0, Cos>
{
public:
	constexpr double operator()() const { return 1.0; }
};
