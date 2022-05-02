#pragma once
#include "Factorial.hpp"
#include "Power.hpp"

template<auto x>
struct Exponential
{
	//Here we calculate e^x. Fact 20 is the biggest value we can get without getting wrong values.
	//This function isn't as precise as the exp(x) function.
	constexpr long double operator()() const {
		return  static_cast<long double>(1.0) + x +
			(1.0 / static_cast<long double>(Factorial<2>()())) * PowD<x, 2>()() +
			(1.0 / static_cast<long double>(Factorial<3>()())) * PowD<x, 3>()() +
			(1.0 / static_cast<long double>(Factorial<4>()())) * PowD<x, 4>()() +
			(1.0 / static_cast<long double>(Factorial<5>()())) * PowD<x, 5>()() +
			(1.0 / static_cast<long double>(Factorial<6>()())) * PowD<x, 6>()() +
			(1.0 / static_cast<long double>(Factorial<7>()())) * PowD<x, 7>()() +
			(1.0 / static_cast<long double>(Factorial<8>()())) * PowD<x, 8>()() +
			(1.0 / static_cast<long double>(Factorial<9>()())) * PowD<x, 9>()() +
			(1.0 / static_cast<long double>(Factorial<10>()())) * PowD<x, 10>()() +
			(1.0 / static_cast<long double>(Factorial<11>()())) * PowD<x, 11>()() +
			(1.0 / static_cast<long double>(Factorial<12>()())) * PowD<x, 12>()() +
			(1.0 / static_cast<long double>(Factorial<13>()())) * PowD<x, 13>()() +
			(1.0 / static_cast<long double>(Factorial<14>()())) * PowD<x, 14>()() +
			(1.0 / static_cast<long double>(Factorial<15>()())) * PowD<x, 15>()() +
			(1.0 / static_cast<long double>(Factorial<16>()())) * PowD<x, 16>()() +
			(1.0 / static_cast<long double>(Factorial<17>()())) * PowD<x, 17>()() +
			(1.0 / static_cast<long double>(Factorial<18>()())) * PowD<x, 18>()() +
			(1.0 / static_cast<long double>(Factorial<19>()())) * PowD<x, 19>()() +
			(1.0 / static_cast<long double>(Factorial<20>()())) * PowD<x, 20>()();
	}
};

