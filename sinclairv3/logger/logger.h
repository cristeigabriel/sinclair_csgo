#pragma once

#include <cstdio>
#include <cstdlib>

#pragma warning(disable:4172)

namespace logger {
	namespace init {
		void the();
	}

	namespace types {
		typedef unsigned int level_type;
	}

	namespace level {
		constexpr static types::level_type warning = 0;
		constexpr static types::level_type error = 1;
		constexpr static types::level_type log = 2;

		namespace naming {
			constexpr static const char* the[log + 1] /* lol */ = { "warning", "error", "log" };
		}
	}

	//  this is kinda disgusting but works
	template <types::level_type level, size_t N, typename... Args>
	inline void the(const char(&fmt)[N], Args... args) {
		printf("%s | ", logger::level::naming::the[level]);

		printf(fmt, args...);
	}
}