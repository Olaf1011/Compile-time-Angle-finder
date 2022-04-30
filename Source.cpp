#include <algorithm>
#include <iostream>
#include <array>
#include <vector>


#include "Timer.h"
#include "Angles.hpp"

static LARGE_INTEGER qpc_freq;
static LARGE_INTEGER qpc_begin;
static LARGE_INTEGER qpc_end;
static double timer_multiplier;

class testing
{
public:
	unsigned long long value = Factorial<40>::result;
};

void TimerFunc(double& timeSave, double (*func)(int))
{
	constexpr int J_VALUE = 10000;
	constexpr int I_VALUE = 360;
	std::vector<double> localVec(J_VALUE * I_VALUE);
	QueryPerformanceCounter(&qpc_begin);
	for(int j = 0; j < J_VALUE; ++j)
	{
		for (int i = 0; i < I_VALUE; ++i)
		{
			localVec.emplace_back(func(i));
		}
	}
	QueryPerformanceCounter(&qpc_end);
	localVec.clear();
	timeSave = (double)(qpc_end.QuadPart - qpc_begin.QuadPart) / timer_multiplier;
}

void AnglesLookUp()
{
	Timer timer;

	double times[6] = {};
	QueryPerformanceFrequency(&qpc_freq);
	timer_multiplier = (double)qpc_freq.QuadPart;

	TimerFunc(times[0], LookUpFunc);
	TimerFunc(times[0], LookUpFunc);
	TimerFunc(times[0], LookUpFunc);

	TimerFunc(times[0], PureLookUp);
	TimerFunc(times[1], LookUp);
	TimerFunc(times[2], SinPrint);

	TimerFunc(times[5], SinPrint);
	TimerFunc(times[4], LookUp);
	TimerFunc(times[3], PureLookUp);

	std::cout << "Time for Pure lookup: " << times[0] << std::endl;
	std::cout << "Time for lookup: " << times[1] << std::endl;
	std::cout << "Time for sin() func: " << times[2] << std::endl;
	std::cout << std::endl;
	std::cout << "Time for rev Pure lookup: " << times[3] << std::endl;
	std::cout << "Time for rev lookup: " << times[4] << std::endl;
	std::cout << "Time for rev sin() func: " << times[5] << std::endl;
}

void FactorialTemplateFunc()
{
	double times;
	TimerFunc(times, LookUpFunc);
	TimerFunc(times, LookUpFunc);
	TimerFunc(times, LookUpFunc);
	Timer timer;
	unsigned long long factorial = 1;
	constexpr int max = 40;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	
	timer.Start();
	std::cout << "Factorial of " << "warm up" << " = " << Factorial<max>::result << std::endl;
	timer.StopPrint();

	timer.Start();
	std::cout << "Factorial of test " << max << " = " << 18376134811363311616 << std::endl;
	timer.StopPrint();
	
	timer.Start();
	std::cout << "Factorial of template with " << max << " = " << Factorial<max>::result << std::endl;
	timer.StopPrint();

	timer.Start();
	std::cout << "Factorial of template with hard coded " << max << " = " << Factorial<40>::result << std::endl;
	timer.StopPrint();
	
	timer.Start();
	for (int i = 1; i <= max; ++i) {
		factorial *= i;
	}
	std::cout << "Factorial of for loop " << max << " = " << factorial << std::endl;
	timer.StopPrint();

}


int main(void)
{

	//constexpr Angles<20, Sin> values;
	
	constexpr double Y = s_sinManualAngles[1];
	std::cout << Y << std::endl;
	constexpr double test = AngleFinder<20, Sin>::value;
	//AnglesLookUp();
	//FactorialTemplateFunc();
	double times;
	TimerFunc(times, LookUpFunc);
	TimerFunc(times, LookUpFunc);
	TimerFunc(times, LookUpFunc);
	Timer timer;
	constexpr int max = 5;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	std::cout << "warm up" << " = " << Factorial<max>::result << std::endl;
	//timer.Start();
	//std::cout << "Template " << AngleFinder<Factorial<5>::result, Sin>::value << std::endl;
	//timer.StopPrint();

	//timer.Start();
	//unsigned long long factorial = 1;
	//for (int i = 1; i <= max; ++i) {
	//	factorial *= i;
	//}
	//std::cout << "Sin + For loop: " << sin((double)factorial * PI / 180.0) << std::endl;
	//timer.StopPrint();
	timer.Start();
	unsigned long long factorial = 1;
	for (int i = 1; i <= max; ++i) {
		factorial *= i;
	}
	std::cout << "Sin + For loop: " << (sin((double)factorial * PI / 180.0) * 10.0) / (sin(30 * PI / 180.0) + 10.0) << std::endl;
	timer.StopPrint();
	
	timer.Start();
	constexpr double x = (AngleFinder<Factorial<max>::result, Sin>::value * 10.0) / (AngleFinder<30, Sin>::value + 10.0);
	std::cout << "Template " << x << std::endl;
	timer.StopPrint();
	

	
	return EXIT_SUCCESS;
}