#pragma once
#include <windows.h>
#include <array>
#include <iostream>
#include <string>
#include "Factorial.hpp"

#define PI 3.14159265
class Sin;
class Cos;

template<int A, class Type>
struct AngleFinder;

template<>
struct AngleFinder<0, Sin>
{
	static constexpr double value = 0.0;
	constexpr double operator()() const { return value; }
};

template<int X>
struct AngleFinder<X, Sin>
{
private:
	static constexpr double x = static_cast<double>(X) * PI / 180.0;
public:
	static constexpr double value = x - (x * x * x) / Factorial<3>::result + 
									(x * x * x * x * x) / Factorial<5>::result - 
									(x * x * x * x * x * x * x) / Factorial<7>::result + 
									(x * x * x * x * x * x * x * x * x) / Factorial<9>::result - 
									(x * x * x * x * x * x * x * x * x * x * x) / Factorial<11>::result +
									(x * x * x * x * x * x * x * x * x * x * x * x * x) / Factorial<13>::result;
	constexpr double operator()() const { return value; }
};

//template<int A>
//struct AngleFinder<A, Sin>
//{
//	static double value = sin(static_cast<double>(A) * PI / 180);
//	constexpr double operator()() const { return value; }
//};

template<int A>
struct AngleFinder<A, Cos>
{
	const double value = cosf(static_cast<double>(A) * PI / 180);
	double operator()() const { return value; }
};


template <size_t N, class Type>
struct Angles
{
	constexpr Angles() { Angles<N, Type>::Fill(); }
	inline constexpr double& operator[](const size_t i)
	{
		return m_angles[i];
	}
	inline constexpr const double& operator[](const size_t i) const
	{
		return m_angles[i];
	}

	template <size_t I = 0>
	inline constexpr void Fill()
	{
		// Fill out our angle array
		m_angles[I] = AngleFinder<I, Type>::value;
		// recurse upwards
		if constexpr (I + 1 < N + 1) Angles<N, Type>::Fill<I + 1>();
	}
	double m_angles[N + 1];
private:
};

//struct CosAngles
//{
//	CosAngles()
//	{
//		for (int i = 0; i < 361; ++i)
//		{
//			m_angles[i] = cos(i);
//		}
//	}
//
//	std::array<double, 361> m_angles{};
//};

static Angles<360, Sin> s_sinAngles;
//static Angles<360, Cos> s_cosAngles;

inline double SinPrint(int i)
{
	return sin(i * PI / 180);
}

inline double LookUpFunc(int i)
{
	return s_sinAngles[i];
}

inline double LookUp(int i)
{
	return s_sinAngles.m_angles[i];
}
#include "LookUp.hpp"

inline constexpr double PureLookUp(int i)
{
	return s_sinManualAngles[i];
}


//inline void SinPrint(int i)
//{
//	OutputDebugStringW(std::to_wstring(sin(i * PI / 180)).c_str());
//	OutputDebugStringW(L"\n");
//}
//
//inline void LookUpFunc(int i)
//{
//	OutputDebugStringW(std::to_wstring(s_sinAngles[i]).c_str());
//	OutputDebugStringW(L"\n");
//}
//
//inline void LookUp(int i)
//{
//	OutputDebugStringW(std::to_wstring(s_sinAngles.ms_angles[i]).c_str());
//	OutputDebugStringW(L"\n");
//}
//#include "LookUp.hpp"
//
//inline void PureLookUp(int i )
//{
//	OutputDebugStringW(std::to_wstring(s_sinManualAngles[i]).c_str());
//	OutputDebugStringW(L"\n");
//	
//}
