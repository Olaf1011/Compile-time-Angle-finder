#include <algorithm>
#include <iostream>
#include <array>
#include <windows.h>
#include "Timer.h"
#include "Angles.hpp"

static LARGE_INTEGER qpc_freq;
static LARGE_INTEGER qpc_begin;
static LARGE_INTEGER qpc_end;
static double timer_multiplier;


void TimerFunc(double& timeSave, void(*func)(int))
{
	QueryPerformanceCounter(&qpc_begin);
	for(int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < 360; ++i)
		{
			func(i);
		}
	}
	QueryPerformanceCounter(&qpc_end);

	timeSave = (double)(qpc_end.QuadPart - qpc_begin.QuadPart) / timer_multiplier;
}

int main(void)
{
	Timer timer;

	double times[6] = {};
	QueryPerformanceFrequency(&qpc_freq);
	timer_multiplier = (double)qpc_freq.QuadPart;

	TimerFunc(times[0], LookUpFunc);
	TimerFunc(times[0], LookUpFunc);
	TimerFunc(times[0], LookUpFunc);	
	
	TimerFunc(times[0], LookUpFunc);
	TimerFunc(times[1], LookUp);
	TimerFunc(times[2], SinPrint);	

	TimerFunc(times[5], SinPrint);
	TimerFunc(times[4], LookUp);
	TimerFunc(times[3], LookUpFunc);
	
	std::cout << "Time for lookup with func: " << times[0] << std::endl;
	std::cout << "Time for lookup: " << times[1] << std::endl;
	std::cout << "Time for sin() func: " << times[2] << std::endl;
	std::cout << std::endl;
	std::cout << "Time for rev lookup with func: " << times[3] << std::endl;
	std::cout << "Time for rev lookup: " << times[4] << std::endl;
	std::cout << "Time for rev sin() func: " << times[5] << std::endl;
	
	return EXIT_SUCCESS;
}