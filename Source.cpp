#include <iostream>
#include <vector>

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
		Angles(); //Recursive for getting the correct answer
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
		Sqaured(); //Recursive for getting the correct answer
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
		Expo(); //Recursive for getting the correct answer
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
		FactorialFunc(); //Recursive for getting the correct answer
	}
	else
	{
		ull factorial = 1;
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
//!! You will sometimes have to rebuild the solution for things to take effect. !!
void ManualInput()
{
	{
		//Input your manual values for x^y.
		constexpr int x = 5;
		constexpr int y = 20;
		constexpr unsigned long long answer = POW(x, y);
		printf("%i^%i = %llu\n", x, y, answer);
	}
	{
		//Input your manual values for x!.
		constexpr int x = 5;
		constexpr ull answer = FACTORIAL(x);
		printf("%i! = %llu\n", x, answer);
	}
	{
		//Input your manual values for Sin(x) in degrees.
		constexpr int x = 30;  // x in degrees
		constexpr long double answer = SIN(x);
		printf("Sin(%i) = %lf\n", x, answer);
	}
	{
		//Input your manual values for Cos(x) in degrees.
		constexpr int x = 50 + 24; // x in degrees
		constexpr double answer = COS(x);
		printf("Cos(%i) = %f\n", x, answer);
	}
	{
		//Input your manual values for e^x.
		constexpr long double x = 5.0; // x in degrees
		constexpr long double answer = EXP(x);
		printf("e^%lf, = %lf\n", x, answer);
	}
}


void EfficiencyTesting()
{
	Timer timer;

	{
		std::vector<long long unsigned> warmUp2;
		warmUp2.reserve(1000 * 500);
		for (int i = 0; i < 1000; ++i)
		{
			for (int j = 0; j < 500; ++j)
				warmUp2.emplace_back(j * i);
		}
		warmUp2.clear();
	}

	constexpr int loopSizeI = 100000;
	{
		constexpr int loopSizeJ = 50;


		std::vector<long long unsigned> squareVec;
		std::vector<long long unsigned> squareVecRef;

		squareVec.reserve(loopSizeI * loopSizeJ);
		squareVecRef.reserve(loopSizeI * loopSizeJ);

		printf("Squared Look Up: ");
		timer.Start();

		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				squareVecRef.emplace_back(g_SquaredLookUp[j]);
		}
		timer.StopPrint();
		squareVec.clear();


		printf("Pow(x, 2): ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				squareVec.emplace_back(pow(j, 2));
		}
		timer.StopPrint();
		squareVec.clear();
	}

	{
		constexpr int loopSizeJ = 10;

		std::vector<long double> expoVec;
		std::vector<long double> expoVecRef;
		expoVec.reserve(loopSizeI * loopSizeJ);
		expoVecRef.reserve(loopSizeI * loopSizeJ);

		printf("Expo look up: ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
			{
				expoVecRef.emplace_back(g_ExpoLookUp[j]);
			}
		}
		timer.StopPrint();

		expoVecRef.clear();

		printf("Exp(x): ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
			{
				expoVec.emplace_back(exp(j));
			}
		}
		timer.StopPrint();
		expoVec.clear();
	}

	{
		constexpr int loopSizeJ = 360;


		std::vector<double> sinVec;
		std::vector<double> sinVecRef;

		sinVec.reserve(loopSizeI * loopSizeJ);
		sinVecRef.reserve(loopSizeI * loopSizeJ);

		printf("Sin Look Up: ");
		timer.Start();

		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				sinVecRef.emplace_back(g_SinAngles[j]);
		}
		timer.StopPrint();
		sinVec.clear();


		printf("Sin(x): ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				sinVec.emplace_back(sin(j));
		}
		timer.StopPrint();
		sinVec.clear();
	}

	{
		constexpr int loopSizeJ = 360;


		std::vector<double> cosVec;
		std::vector<double> cosVecRef;
		cosVec.reserve(loopSizeI * loopSizeJ);
		cosVecRef.reserve(loopSizeI * loopSizeJ);

		printf("Cos Look Up: ");
		timer.Start();

		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				cosVecRef.emplace_back(g_CosAngles[j]);
		}
		timer.StopPrint();
		cosVec.clear();


		printf("Cos(x): ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				cosVec.emplace_back(cos(j));
		}
		timer.StopPrint();
		cosVec.clear();
	}
	{
		constexpr int loopSizeJ = 20;


		std::vector<long long unsigned> facVec;
		std::vector<long long unsigned> facVecRef;

		facVec.reserve(loopSizeI * loopSizeJ);
		facVecRef.reserve(loopSizeI * loopSizeJ);

		printf("Factorial look up: ");
		timer.Start();

		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
				facVecRef.emplace_back(g_FactorialLookUp[j]);
		}
		timer.StopPrint();
		facVec.clear();


		printf("For loop fact(x): ");
		timer.Start();
		for (int i = 0; i < loopSizeI; ++i)
		{
			for (int j = 0; j < loopSizeJ; ++j)
			{
				ull factorial = 1;
				for (int k = 1; k <= j; ++k) {
					factorial *= k;
				}
				facVec.emplace_back(factorial);
			}
		}
		timer.StopPrint();
		facVec.clear();
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