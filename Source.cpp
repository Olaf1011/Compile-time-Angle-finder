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
	
	std::cout << cos(3.0) << " Cos()" << std::endl;
	std::cout << AngleFinder<3, Cos>()() << " Mine" << std::endl;

	
	return EXIT_SUCCESS;
}