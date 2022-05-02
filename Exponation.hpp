#pragma once
#include "Factorial.hpp"
#include "Power.hpp"

template<int x>
struct exponential
{
	//Here we calculate e^x. Fact 19 > has to be cast to a long double as fact 19 is too big for a double
	constexpr auto operator()() const {
		return 1.0 + x + (1.0 / Factorial<2>()()) * PowD<x, 2>()() +
						 (1.0 / Factorial<3>()()) * PowD<x, 3>()() +
						 (1.0 / Factorial<4>()()) * PowD<x, 4>()() +
						 (1.0 / Factorial<5>()()) * PowD<x, 5>()() +
						 (1.0 / Factorial<6>()()) * PowD<x, 6>()() + 
						 (1.0 / Factorial<7>()()) * PowD<x, 7>()() +
						 (1.0 / Factorial<8>()()) * PowD<x, 8>()() +
						 (1.0 / Factorial<9>()()) * PowD<x, 9>()() +
						 (1.0 / Factorial<10>()()) * PowD<x, 10>()() + 
						 (1.0 / Factorial<11>()()) * PowD<x, 11>()() +
						 (1.0 / Factorial<12>()()) * PowD<x, 12>()() +
						 (1.0 / Factorial<13>()()) * PowD<x, 13>()() +
						 (1.0 / Factorial<14>()()) * PowD<x, 14>()() +
						 (1.0 / Factorial<15>()()) * PowD<x, 15>()() +
						 (1.0 / Factorial<16>()()) * PowD<x, 16>()() +
						 (1.0 / Factorial<17>()()) * PowD<x, 17>()() +
						 (1.0 / Factorial<18>()()) * PowD<x, 18>()() +
						 (1.0 / static_cast<long double>(Factorial<19>()())) * PowD<x, 19>()() +
						 (1.0 / static_cast<long double>(Factorial<20>()())) * PowD<x, 20>()() +
						 (1.0 / static_cast<long double>(Factorial<21>()())) * PowD<x, 21>()();
	}
};

