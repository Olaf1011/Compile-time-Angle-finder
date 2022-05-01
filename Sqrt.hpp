#pragma once
#include "Factorial.hpp"
#include "Power.hpp"
//
//template<auto x, int n = 5>
//struct Sqrt
//{
//	static constexpr auto value = Sqrt<x, n - 1>::value + (Factorial<(2 * n)>()() * Pow<(1.0 - x), n>()() * x) / (Pow<(Factorial<n>()()* Pow<2, n>()()), 2>()());
//};
//
////template<auto x>
////struct Sqrt<x, 0>
////{
////	static constexpr auto value = (Factorial<(2 * 0)>()() * Pow<(1.0 - x), 0>()() * x) / (Pow<(Factorial<0>()()* Pow<2, 0>()()), 2>()());
////};
////
////template<auto x, int n = 5>
////struct Sqrt
////{
////	static constexpr auto value = 1.0 + ((1.0 / 2.0) * (x - 1.0) ) - ((1.0 / 8.0) * Pow<x - 1, 2>()()) + ((1.0 / 16.0) * Pow<x - 1, 3>()()) - ((5.0 / 128.0) * Pow<x - 1, 4>()()) + ((6.0 / 256.0) * Pow<x - 1, 5>()()) - ((7.0 / 512.0) * Pow<x - 1, 6>()());
////};
//
//template<auto x, int n = 5>
//struct Sqrt
//{
//	static constexpr auto value = 1.0 + (x / 2.0) - (Pow<x, 2>()() / 8.0) + (Pow<x, 3>()() / 16);
//};
//
//
//template<auto x>
//struct Sqrt<x, 0>
//{
//	static constexpr auto value = (Factorial<(2 * 0)>()() * Pow<(1.0 - x), 0>()() * x) / (Pow<(Factorial<0>()()* Pow<2, 0>()()), 2>()());
//};
