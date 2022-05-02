#include <iostream>

#include "Timer.h"
#include "SinLookUp.hpp"
#include "CosLookUp.hpp"
#include "Angles.hpp"
#include "Exponation.hpp"
#include "SquaredLookUp.hpp"
#include "ExpoLookUp.hpp"
#include "FactorialLookUp.hpp"
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
		printf("%i^2 = %llu Using a look up table\n%i^2 = %llu using pow() function", value, g_SquaredLookUp[value - 1], value, static_cast<ull>(pow(value, 2)));
		std::cout << std::endl << std::endl << std::endl;
	}
}


void Expo()
{
	int value = 0; //Default 0 to make sure it gets filled with a value
	std::string inputValue;
	char* pEnd = nullptr;

	std::cout << "Input a value for e^x (Limited to 1 - 9)\nIf you want to calculate e^x and pick your own values\nUse function \"ManualInput()\" and input your own value\nInput: ";
	std::cin >> inputValue;
	value = std::strtol(inputValue.c_str(), &pEnd, 10);

	system("CLS");

	//Check for valid value.
	if (value > 9 || value < 1)
	{
		std::cout << "Please put a space between your choice and the value or use a valid value\n\n" << std::endl;
		Expo();
	}
	else
	{
		printf("e^%i = %lf Using a look up table\ne^%i = %lf using exp() function", value, g_ExpoLookUp[value - 1], value, exp(value));
		std::cout << std::endl << std::endl << std::endl;
	}
}

void FactorialFunc()
{
	int value = 0; //Default 0 to make sure it gets filled with a value
	std::string inputValue;
	char* pEnd = nullptr;

	std::cout << "Input a value for x! (Limited to 1 - 20)\nIf you want to calculate x! and pick your own values\nUse function \"ManualInput()\" and input your own value\nInput: ";
	std::cin >> inputValue;
	value = std::strtol(inputValue.c_str(), &pEnd, 10);

	system("CLS");

	//Check for valid value.
	if (value > 20 || value < 1)
	{
		std::cout << "Please put a space between your choice and the value or use a valid value\n\n" << std::endl;
		FactorialFunc();
	}
	else
	{
		ull factorial = 1.0;
		for (int i = 1; i <= value; ++i) {
			factorial *= i;
		}
		printf("%i! = %llu Using a look up table\n%i! = %llu using for loop", value, g_FactorialLookUp[value - 1], value, factorial);
		std::cout << std::endl << std::endl << std::endl;
	}
}

void Interface()
{
	int input = 0;
	std::string inputValue;
	char* pEnd;
	//Keep looping until exit is called
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
		case 3:
			Expo();
			break;
		case 4:
			FactorialFunc();
			break;
		}
	}
}

//This will calculate the value at compile time, and even show you the value (on vs2022) of the answer when you hover over it.
void ManualInput()
{
	{
		//Input your manual values for x^y.
		constexpr int x = 5;
		constexpr int y = 20;
		constexpr unsigned long long answer = Pow<x, y>()();
		printf("%i^%i = %llu\n", x, y, answer);
	}
	{
		//Input your manual values for x!.
		constexpr int x = 5;
		constexpr ull answer = Factorial<x>()();
		printf("%i! = %llu\n", x, answer);
	}
	{
		//Input your manual values for Sin(x) in degrees.
		constexpr int x = 5;  // x in degrees
		constexpr double answer = Sin<x>()();
		printf("Sin(%i) = %f\n", x, answer);
	}
	{
		//Input your manual values for Cos(x) in degrees.
		constexpr int x = 5; // x in degrees
		constexpr double answer = Cos<x>()();
		printf("Cos(%i) = %f\n", x, answer);
	}
	{
		//Input your manual values for e^x.
		constexpr long double x = 5.0; // x in degrees
		constexpr long double answer = Exponential<x>()();
		printf("e^%lf, = %lf\n", x, answer);
	}
}

int main(void)
{
	//Set to true if you want to run the manual input functions.
	//Set to false to run the interface.
	constexpr bool Manual = false;

	if constexpr (Manual)
	{
		ManualInput();
	}
	else
	{
		Interface();
	}
	return EXIT_SUCCESS;
}