#pragma once

#include <cstdint>
#include <array>

namespace math {
	template <class T, size_t r, size_t c>
	using matrix = std::array<std::array<T, c>, r>;
}