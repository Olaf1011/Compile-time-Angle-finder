#pragma once

template<auto x, int power>
struct Pow
{
	constexpr auto operator()() const { return x * Pow<x, power - 1>()(); }
};

template<auto x>
struct Pow<x, 0>
{
	constexpr auto operator()() const { return 1.0; }
};

