#pragma once

template<auto length, auto width>
struct AreaSquare
{
	constexpr auto operator()() const
	{
		return length * width;
	}
	constexpr auto GetWidth() const { return width; }
	constexpr auto GetLength() const { return length; }
};

template<auto radius>
struct Circle
{
	static constexpr auto area = PI * Pow<radius, 2>()();
	static constexpr auto circumference = 2 * PI * radius;
};