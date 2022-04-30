#include <algorithm>
#include <iostream>
#include <array>
#include <vector>


#include "Timer.h"
#include "Angles.hpp"



int main(void)
{	
	constexpr Factorial<5> testing;

	constexpr ull test = Factorial<5>()();
	
	constexpr ld dtest = test / 0.45;
	
	std::cout << "pow() Power of " << pow(5,	16) << std::endl;
	std::cout << "mine  Power of " << Pow<5.0,	16>()() << std::endl;

	constexpr int n = 14;
	long double factorial = 1.0;

	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	}



	std::cout << "Fact() Power of " << factorial << std::endl;
	std::cout << "mine  Power of " << Factorial<n>()() << std::endl;

	constexpr double x = 30.0;

	std::cout << cos(static_cast<double>(x) * PI / 180.0) << " Cos()" << std::endl;
	std::cout << AngleFinder<(int)x, Cos>()() << " Mine" << std::endl;
	std::cout << sin(static_cast<double>(x) * PI / 180.0) << " Sin()" << std::endl;
	std::cout << AngleFinder<(int)x, Sin>()() << " Mine sin" << std::endl;

	
	return EXIT_SUCCESS;
}