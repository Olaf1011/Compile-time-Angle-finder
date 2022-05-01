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