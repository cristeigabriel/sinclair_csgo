#pragma once

#include <cstdint>

namespace util {
	struct color_t {
		typedef uint8_t color_type;

		color_type r;
		color_type g;
		color_type b;
		color_type a;
	};
}