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

int main(void)
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
	
	return EXIT_SUCCESS;
}