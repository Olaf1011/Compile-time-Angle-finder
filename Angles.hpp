#pragma once

#include "Factorial.hpp"

constexpr double PI = 3.14159265;
class Sin;
class Cos;
class Degrees;
class Radians;

template<double x, int power>
struct Pow
{
	constexpr double operator()() const { return x * Pow<x, power - 1>()(); }
};

template<double x>
struct Pow<x, 0>
{
	constexpr double operator()() const { return 1.0; }
};

template<auto A, class Type, class Form = Degrees>
class AngleFinder;

template<double x>
class AngleFinder<x, Sin, Radians>
{
public:
	constexpr double operator()() const {
		return x - Pow<x, 3>()()  / Factorial<3>()() +
													 Pow<x, 5>()()  / Factorial<5>()() -
													 Pow<x, 7>()()  / Factorial<7>()() +
													 Pow<x, 9>()()  / Factorial<9>()() -
													 Pow<x, 11>()() / Factorial<11>()() +
													 Pow<x, 13>()() / Factorial<13>()(); }
};

template<int X>
class AngleFinder<X, Sin, Degrees>
{
	static constexpr double x = static_cast<double>(X) * PI / 180.0;
public:
	constexpr double operator()() const { return AngleFinder<x, Sin, Radians>()(); }
};

template<double x>
class AngleFinder<x, Cos, Radians>
{
public:
	constexpr double operator()() const { return	1.0 -	Pow<x, 2>()() / Factorial<2>()() +
												Pow<x, 4>()() / Factorial<4>()() -
												Pow<x, 6>()() / Factorial<6>()() +
												Pow<x, 8>()() / Factorial<8>()() -
												Pow<x, 10>()() / Factorial<10>()() +
												Pow<x, 12>()() / Factorial<12>()(); }
};

template<int X>
class AngleFinder<X, Cos, Degrees>
{
	static constexpr double x = static_cast<double>(X) * PI / 180.0;
public:
	constexpr double operator()() const { return AngleFinder<x, Cos, Radians>()(); }
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
