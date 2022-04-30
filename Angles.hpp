#pragma once

#include "Factorial.hpp"

constexpr double PI = 3.14159265;
class SinAngle;
class CosAngle;
class Degrees;
class Radians;

template<auto x, int power>
struct Pow
{
	constexpr auto operator()() const { return x * Pow<x, power - 1>()(); }
};

template<auto x>
struct Pow<x, 0>
{
	constexpr auto operator()() const { return 1.0; }
};

template<int X, class Type>
class AngleFinder;

template<int X>
class AngleFinder<X, SinAngle>
{
public:
	constexpr double operator()() const {
		if constexpr (X > 360)
			return AngleFinder<X - 360, SinAngle>()();

		if constexpr (X == 180 || X == 360 || X == 0)
			return 0.0;
		else if constexpr (X == 90)
			return 1.0;
		else if constexpr (X == 270)
			return -1.0;

		constexpr double x = static_cast<double>(X) * PI / 180.0;
		return x -	Pow<x, 3>()()  / Factorial<3>()() +
					Pow<x, 5>()()  / Factorial<5>()() -
					Pow<x, 7>()()  / Factorial<7>()() +
					Pow<x, 9>()()  / Factorial<9>()() -
					Pow<x, 11>()() / Factorial<11>()() +
					Pow<x, 13>()() / Factorial<13>()();
	}
};

template<int X>
class AngleFinder<X, CosAngle>
{
public:
	constexpr double operator()() const {
		if constexpr (X > 360)
			return AngleFinder<X - 360, CosAngle>()();


		if constexpr (X == 90 || X == 270)
			return 0.0;
		else if constexpr (X == 0 || X == 360)
			return 1.0;
		else if constexpr (X == 180)
			return -1.0;

		constexpr double x = static_cast<double>(X) * PI / 180.0;
		return	1.0 -	Pow<x, 2>()() / Factorial<2>()() +
						Pow<x, 4>()() / Factorial<4>()() -
						Pow<x, 6>()() / Factorial<6>()() +
						Pow<x, 8>()() / Factorial<8>()() -
						Pow<x, 10>()() / Factorial<10>()() +
						Pow<x, 12>()() / Factorial<12>()(); }
};

template<int X>
using Cos = AngleFinder<X, CosAngle>;
template<int X>
using Sin = AngleFinder<X, SinAngle>;