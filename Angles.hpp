#pragma once

#include "Factorial.hpp"
#include "Power.hpp"

constexpr double PI = 3.14159265;
class SinAngle;
class CosAngle;

template<int X, class Type>
struct AngleFinder;

template<int X>
struct AngleFinder<X, SinAngle>
{
	constexpr double operator()() const {
		//Check if the number is bigger than 360.
		//Use recursive to decrease the number and check again.
		//Mostly used to keep our radians within the normal limits.
		if constexpr (X > 360)
			return AngleFinder<X - 360, SinAngle>()();

		//Check for values that should create a 0. As the normal cos() function, including this formula aren't precise enough to get to 0.
		if constexpr (X == 180 || X == 360 || X == 0)
			return 0.0;
		//Some small optimization as we already know the answer for these.
		else if constexpr (X == 90)
			return 1.0;
		else if constexpr (X == 270)
			return -1.0;
		//Convert degrees too radians as this formula uses radians. Do this after the checks for another small optimization.
		constexpr double x = static_cast<double>(X) * PI / 180.0;
		//Here we calculate the actual answer at compile time.
		return x -	Pow<x, 3>()()  / Factorial<3>()() +
					Pow<x, 5>()()  / Factorial<5>()() -
					Pow<x, 7>()()  / Factorial<7>()() +
					Pow<x, 9>()()  / Factorial<9>()() -
					Pow<x, 11>()() / Factorial<11>()() +
					Pow<x, 13>()() / Factorial<13>()();
	}
};

template<int X>
struct AngleFinder<X, CosAngle>
{
	//Using degrees to calculate the cosine.
	constexpr double operator()() const {
		//Check if the number is bigger than 360.
		//Use recursive to decrease the number and check again.
		//Mostly used to keep our radians within the normal limits.
		if constexpr (X > 360)
			return AngleFinder<X - 360, CosAngle>()();

		//Check for values that should create a 0. As the normal cos() function, including this formula aren't precise enough to get to 0.
		if constexpr (X == 90 || X == 270)
			return 0.0;
		//Some small optimization as we already know the answer for these.
		else if constexpr (X == 0 || X == 360)
			return 1.0;
		else if constexpr (X == 180)
			return -1.0;

		//Convert degrees too radians as this formula uses radians. Do this after the checks for another small optimization.
		constexpr double x = static_cast<double>(X) * PI / 180.0;
		//Here we calculate the actual answer at compile time.
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