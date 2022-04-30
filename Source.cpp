#include <iostream>
#include <array>

#include "Timer.h"
#include "SinLookUp.hpp"
#include "CosLookUp.hpp"
#include "Angles.hpp"

int main(void)
{	
	constexpr Factorial<5> testing;

	constexpr ull test = Factorial<5>()();
	
	constexpr long double dtest = testing / 0.45;
	
	std::cout << "pow() Power of " << pow(5,	16) << std::endl;
	std::cout << "mine  Power of " << Pow<5.0,	16>()() << std::endl;

	constexpr int n = 14;
	long double factorial = 1.0;

	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	}

	std::cout << std::endl;
	std::cout << "Fact() Power of " << factorial << std::endl;
	std::cout << "mine  Power of " << Factorial<n>()() << std::endl;

	std::cout << std::endl;
	constexpr double x = 180.0;

	std::cout << cos(static_cast<double>(x) * PI / 180.0) << " Cos()" << std::endl;
	std::cout << Cos<(int)x>()() << " Mine" << std::endl;
	std::cout << g_CosAngles[(int)x] << " Look up" << std::endl;
	std::cout << std::endl;

	std::cout << sin(static_cast<double>(x) * PI / 180.0) << " Sin()" << std::endl;
	std::cout << Sin<(int)x>()() << " Mine sin" << std::endl;
	std::cout << Sin<(int)(360.0 + x)>()() << " 450 sin" << std::endl;
	std::cout << g_SinAngles[(int)x] << " Look up" << std::endl;
	std::cout << std::endl;


	return EXIT_SUCCESS;
}