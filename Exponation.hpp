#pragma once
#include "Factorial.hpp"
#include "Power.hpp"

template<int x>
struct exponential
{
	//Here we calculate e^x. This is roughly the limit of how precise we can get as factorial 19 is too big for a double.
	constexpr auto operator()() const {
		return 1.0 + x + (1.0 / Factorial<2>()()) * Pow<x, 2>()() +
						 (1.0 / Factorial<3>()()) * Pow<x, 3>()() +
						 (1.0 / Factorial<4>()()) * Pow<x, 4>()() +
						 (1.0 / Factorial<5>()()) * Pow<x, 5>()() +
						 (1.0 / Factorial<6>()()) * Pow<x, 6>()() + 
						 (1.0 / Factorial<7>()()) * Pow<x, 7>()() +
						 (1.0 / Factorial<8>()()) * Pow<x, 8>()() +
						 (1.0 / Factorial<9>()()) * Pow<x, 9>()() +
						 (1.0 / Factorial<10>()()) * Pow<x, 10>()() + 
						 (1.0 / Factorial<11>()()) * Pow<x, 11>()() +
						 (1.0 / Factorial<12>()()) * Pow<x, 12>()() +
						 (1.0 / Factorial<13>()()) * Pow<x, 13>()() +
						 (1.0 / Factorial<14>()()) * Pow<x, 14>()() +
						 (1.0 / Factorial<15>()()) * Pow<x, 15>()() +
						 (1.0 / Factorial<16>()()) * Pow<x, 16>()() +
						 (1.0 / Factorial<17>()()) * Pow<x, 17>()() +
						 (1.0 / Factorial<18>()()) * Pow<x, 18>()();
	}
};

