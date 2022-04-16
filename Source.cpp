#include <algorithm>
#include <iostream>
#include <array>

class Sin;
class Cos;

template<int A, class Type>
struct AngleFinder;

template<int A>
struct AngleFinder<A, Sin>
{
	const float value = sinf(static_cast<float>(A));
	float operator()() const { return value; }
};

template<int A>
struct AngleFinder<A, Cos>
{
	const float value = cosf(static_cast<float>(A));
	float operator()() const { return value; }
};


template <size_t N, class Type>
struct Angles
{
	Angles() { Fill(this); }
	float& operator[](const size_t i)
	{
		if (i > 360)
			return ms_angles[i - 360];
		else
			return ms_angles[i];

	}
	const float& operator[](const size_t i) const
	{
		if (i > 360)
			return ms_angles[i - 360];
		else
			return ms_angles[i];
	}
	
	template <size_t I = 0>
	static void Fill(Angles* ptr)
	{
		// Fill out our angle array
		ptr->ms_angles[I] = AngleFinder<static_cast<int>(I), Type>()();
		// recurse upwards
		if constexpr (I + 1 < N + 1) Angles<N, Type>::Fill<I + 1>(ptr);
	}
private:
	std::array<float, N + 1> ms_angles;
};

static Angles<360, Sin> s_sinAngles;
static Angles<360, Cos> s_cosAngles;

int main(void)
{
	constexpr size_t testValue = 360;
	std::cout << s_sinAngles[testValue] << std::endl;
	std::cout << sinf(testValue) << std::endl;
	
	std::cout << s_cosAngles[testValue] << std::endl;
	std::cout << cosf(testValue) << std::endl;
	
	return EXIT_SUCCESS;
}