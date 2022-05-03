#pragma once

#include "Factorial.hpp"
#include "Power.hpp"

constexpr double PI = 3.14159265;
class SinAngle;
class CosAngle;

template<int X, class Type>
class AngleFinder;

template<int X>
class AngleFinder<X, SinAngle>
{
protected:
	friend class AngleFinder <X - 360, SinAngle>; //An ugly fix to allow for hiding variables and not making the visible for the end user
	friend class AngleFinder <X + 360, SinAngle>;
	//Check if the number is bigger than 360.
	//Use recursive to decrease the number and check again.
	//Mostly used to keep our radians within the normal limits.
	static constexpr unsigned Reducer() {
		if constexpr (X > 360)
			return AngleFinder<X - 360, SinAngle>::Reducer();
		else if constexpr (X < -360)
			return AngleFinder<X + 360, SinAngle>::Reducer();
		else
			return X;
	}
	static constexpr int reducer = Reducer();
	//Convert degrees too radians as this formula uses radians.
	static constexpr double x = static_cast<double>(reducer) * PI / 180.0;
public:
	//Here we calculate the actual answer at compile time.
	//Check for values that should create a 0. As the normal cos() function, including this formula aren't precise enough to get to 0.
	static constexpr long double value = reducer == 180 || reducer == 360 || reducer == 0 ? 0.0 :
										x - POWD(x, 3) / FACTORIAL(3) +
											POWD(x, 5) / FACTORIAL(5) -
											POWD(x, 7) / FACTORIAL(7) +
											POWD(x, 9) / FACTORIAL(9) -
											POWD(x, 11) / FACTORIAL(11) +
											POWD(x, 13) / FACTORIAL(13);
};


template<int X>
class AngleFinder<X, CosAngle>
{
protected:
	friend class AngleFinder <X - 360, CosAngle>; //An ugly fix to allow for hiding variables and not making the visible for the end user
	friend class AngleFinder <X + 360, CosAngle>;
	//Check if the number is bigger than 360.
	//Use recursive to decrease the number and check again.
	//Mostly used to keep our radians within the normal limits.
	static constexpr unsigned Reducer() {
		if constexpr (X > 360)
			return AngleFinder<X - 360, CosAngle>::Reducer();
		else if constexpr (X < -360)
			return AngleFinder<X + 360, CosAngle>::Reducer();
		else
			return X;
	}
	static constexpr int reducer = Reducer();
	//static constexpr int reducer = Reducer();
	//Convert degrees too radians as this formula uses radians.
	static constexpr double x = static_cast<double>(reducer) * PI / 180.0;
public:
	//Here we calculate the actual answer at compile time.
	//Check for values that should create a 0. As the normal cos() function, including this formula aren't precise enough to get to 0.
	static constexpr long double value = reducer == 90 || reducer == 270 ? 0.0 :
			1.0 -	POWD(x, 2) / FACTORIAL(2) +
					POWD(x, 4) / FACTORIAL(4) -
					POWD(x, 6) / FACTORIAL(6) +
					POWD(x, 8) / FACTORIAL(8) -
					POWD(x, 10) / FACTORIAL(10) +
					POWD(x, 12) / FACTORIAL(12);
};

#define SIN(X) AngleFinder<X, SinAngle>::value
#define COS(X) AngleFinder<X, CosAngle>::value

