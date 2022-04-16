#pragma once
#include <windows.h>

class Timer
{
	LARGE_INTEGER qpc_freq;
	LARGE_INTEGER qpc_begin;
	LARGE_INTEGER qpc_end;
	double timer_multiplier;
	double time;
	
public:
	Timer() : time(0.0)
	{
		QueryPerformanceFrequency(&qpc_freq);
		timer_multiplier = (double)qpc_freq.QuadPart;
	}

	void Start();
	void Stop();
	void StopPrint();
	double GetTime() const;
	void PrintTime() const;
};
