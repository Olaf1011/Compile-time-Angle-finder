#include <algorithm>
#include <iostream>
#include <array>


struct Angles
{
	float& operator[](size_t&& i) { return ms_angles[i + 1]; }
	const float& operator[](size_t&& i) const { return ms_angles[i + 1]; }
private:
	std::array<float, 360> ms_angles;
};

static Angles s_angles;


template<int A>
struct AngleFinder;

template<int A>
struct AngleFinder
{
	const float value = sinf(static_cast<float>(A));
	float operator()() const { return value; }
};

template <size_t N>
struct ForEach {

	template <size_t I>
	static void item() {

		// Fill out our angle array
		s_angles[I - 1] = AngleFinder<static_cast<int>(I)>()();
		// recurse upwards
		if constexpr (I + 1 < N) ForEach<N>::item<I + 1>();

	}
};

int main(void)
{
	ForEach<360>::item<0>();

	std::cout << s_angles[20] << std::endl;

	std::cout << sinf(21) << std::endl;
	
	system("pause");
	
	return EXIT_SUCCESS;
}