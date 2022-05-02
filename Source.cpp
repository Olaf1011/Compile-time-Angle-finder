#include <iostream>

#include "Timer.h"
#include "SinLookUp.hpp"
#include "CosLookUp.hpp"
#include "Angles.hpp"
#include "Exponation.hpp"
#include "SquaredLookUp.hpp"
#include "Sqrt.hpp"

void Angles()
{
	int choice = 0;
	int value = -1; //Default -1 to make sure it gets filled with a value
	std::string inputChoice;
	std::string inputValue;
	char* pEnd = nullptr;

	std::cout << "Cos Or Sin? + Value(Between 0 - 360)\n1. Cos:\n2. Sin:\nInput: ";
	std::cin >> inputChoice >> inputValue;
	choice = std::strtol(inputChoice.c_str(), &pEnd, 10);
	value = std::strtol(inputValue.c_str(), &pEnd, 10);

	system("CLS");

	//Check for valid value.
	if(value > 360 || value < 0)
	{
		std::cout << "Please put a space between your choice and the value or use a valid value\n\n" << std::endl;
		Angles();
	}
	else
	{
		if(choice == 1)
			printf("Cos(%i) = %e Using a look up table\nCos(%i) = %e using cos() function", value, g_CosAngles[value], value, cos(value * PI / 180.0));
		else if(choice == 2)
			printf("Sin(%i) = %e Using a look up table\nSin(%i) = %e using cos() function", value, g_SinAngles[value], value, sin(value * PI / 180.0));
		std::cout << std::endl << std::endl << std::endl;
	}
}

void Sqaured()
{
	int value = 0; //Default 0 to make sure it gets filled with a value
	std::string inputValue;
	char* pEnd = nullptr;

	std::cout << "Input a value for x^2 (Limited to 1 - 50)\nIf you want to calculate x^y and pick your own values\nUse function \"ManualInput()\" and input your own value\nInput: ";
	std::cin  >> inputValue;
	value = std::strtol(inputValue.c_str(), &pEnd, 10);

	system("CLS");

	//Check for valid value.
	if (value > 50 || value < 1)
	{
		std::cout << "Please put a space between your choice and the value or use a valid value\n\n" << std::endl;
		Sqaured();
	}
	else
	{
		printf("%i^2 = %i Using a look up table\n%i^2 = %i using pow() function", value, g_SquaredLookUp[value - 1], value, static_cast<int>(pow(value, 2)));
		std::cout << std::endl << std::endl << std::endl;
	}
}

void Interface()
{
	int input = 0;
	std::string inputValue;
	char* pEnd;
	//Keep looping untill exit is called
	while(input != 5)
	{
		std::cout << "Pick input:" << std::endl;
		std::cout << "1. Angles:\n2. Power of:\n3. e^x:\n4. Factorial:\n5. Exit:\nInput: ";
		std::cin >> inputValue;
		input = std::strtol(inputValue.c_str(), &pEnd, 10);
		system("CLS");
		switch(input)
		{
		case 1:
			Angles();
			break;
		case 2:
			Sqaured();
			break;
		}
	}
}

void ManualInput()
{
	//Input your manual values for x^y.
	//This will calculate the value at compile time, and even show you the value (on vs2022) of the answer when you hover over it.
	constexpr int x = 2;
	constexpr int y = 2;
	constexpr int answer = Pow<x, y>()();

	std::cout << answer << std::endl;



}

void Testing()
{
	constexpr Factorial<5> testing;

	constexpr ull test = Factorial<5>()();

	std::cout << "pow() Power of " << pow(5, 16) << std::endl;
	std::cout << "mine  Power of " << PowD<5, 16>()() << std::endl;

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

	std::cout << cos(x * PI / 180.0) << " Cos()" << std::endl;
	std::cout << Cos<(int)x>()() << " Mine" << std::endl;
	std::cout << g_CosAngles[(int)x] << " Look up" << std::endl;
	std::cout << std::endl;

	std::cout << sin(x * PI / 180.0) << " Sin()" << std::endl;
	std::cout << Sin<(int)x>()() << " Mine sin" << std::endl;
	std::cout << Sin<(int)(360.0 + x)>()() << " 450 sin" << std::endl;
	std::cout << g_SinAngles[(int)x] << " Look up" << std::endl;
	std::cout << std::endl;

	std::cout << pow(26, 0.5) << std::endl;

	constexpr double exp = exponential<6>()();
}

int main(void)
{

	constexpr bool Manual = false; //Set to true if you want to run the manual input functions.

	if constexpr (Manual)
	{
		ManualInput();
	}


	return EXIT_SUCCESS;
}