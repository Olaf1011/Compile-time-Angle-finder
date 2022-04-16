#include "Timer.h"

#include <iostream>

void Timer::Start()
{
	QueryPerformanceCounter(&qpc_begin);
}

void Timer::Stop()
{
	QueryPerformanceCounter(&qpc_end);
	time = static_cast<double>(qpc_end.QuadPart - qpc_begin.QuadPart) / timer_multiplier;
}

void Timer::StopPrint()
{
	QueryPerformanceCounter(&qpc_end);
	time = static_cast<double>(qpc_end.QuadPart - qpc_begin.QuadPart) / timer_multiplier;
	PrintTime();
}

double Timer::GetTime() const
{
	return time;
}
void Timer::PrintTime() const
{
	std::cout << time << std::endl;
}
	