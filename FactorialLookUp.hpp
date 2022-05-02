#pragma once
#include "Factorial.hpp"

constexpr long long unsigned g_FactorialLookUp[20]
{
	Factorial<1>()(),
	Factorial<2>()(),
	Factorial<3>()(),
	Factorial<4>()(),
	Factorial<5>()(),
	Factorial<6>()(),
	Factorial<7>()(),
	Factorial<8>()(),
	Factorial<9>()(),
	Factorial<10>()(),
	Factorial<11>()(),
	Factorial<12>()(),
	Factorial<13>()(),
	Factorial<14>()(),
	Factorial<15>()(),
	Factorial<16>()(),
	Factorial<17>()(),
	Factorial<18>()(),
	Factorial<19>()(),
	Factorial<20>()()
};
