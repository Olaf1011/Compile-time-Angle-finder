#pragma once
#include "Factorial.hpp"
#include "Power.hpp"

template<auto x>
struct Exponential
{
	//Here we calculate e^x. Fact 20 is the biggest value we can get without getting wrong values.
	//This function isn't as precise as the exp(x) function.
	static constexpr long double value =   static_cast<long double>(1.0) + x +
			(1.0 / static_cast<long double>(FACTORIAL(2))) * POWD(x, 2) +
			(1.0 / static_cast<long double>(FACTORIAL(3))) * POWD(x, 3) +
			(1.0 / static_cast<long double>(FACTORIAL(4))) * POWD(x, 4) +
			(1.0 / static_cast<long double>(FACTORIAL(5))) * POWD(x, 5) +
			(1.0 / static_cast<long double>(FACTORIAL(6))) * POWD(x, 6) +
			(1.0 / static_cast<long double>(FACTORIAL(7))) * POWD(x, 7) +
			(1.0 / static_cast<long double>(FACTORIAL(8))) * POWD(x, 8) +
			(1.0 / static_cast<long double>(FACTORIAL(9))) * POWD(x, 9) +
			(1.0 / static_cast<long double>(FACTORIAL(10))) * POWD(x, 10) +
			(1.0 / static_cast<long double>(FACTORIAL(11))) * POWD(x, 11) +
			(1.0 / static_cast<long double>(FACTORIAL(12))) * POWD(x, 12) +
			(1.0 / static_cast<long double>(FACTORIAL(13))) * POWD(x, 13) +
			(1.0 / static_cast<long double>(FACTORIAL(14))) * POWD(x, 14) +
			(1.0 / static_cast<long double>(FACTORIAL(15))) * POWD(x, 15) +
			(1.0 / static_cast<long double>(FACTORIAL(16))) * POWD(x, 16) +
			(1.0 / static_cast<long double>(FACTORIAL(17))) * POWD(x, 17) +
			(1.0 / static_cast<long double>(FACTORIAL(18))) * POWD(x, 18) +
			(1.0 / static_cast<long double>(FACTORIAL(19))) * POWD(x, 19) +
			(1.0 / static_cast<long double>(FACTORIAL(20))) * POWD(x, 20);
};

#define EXP(x) Exponential<x>::value