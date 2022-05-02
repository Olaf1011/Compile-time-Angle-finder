#pragma once


template<int x, int power>
struct Pow
{
	//Use recursive to calculate the answer to x^y
	constexpr int operator()() const { return x * Pow<x, power - 1>()(); }
};

template<double x, int power>
struct PowD
{
	//Use recursive to calculate the answer to x^y
	constexpr double operator()() const { return x * PowD<x, power - 1>()(); }
};

//The way to end the recursive loop.
template<int x>
struct Pow<x, 0>
{
	constexpr int operator()() const { return 1; }
};

//The way to end the recursive loop.
template<double x>
struct PowD<x, 0>
{
	constexpr double operator()() const { return 1.0; }
};
