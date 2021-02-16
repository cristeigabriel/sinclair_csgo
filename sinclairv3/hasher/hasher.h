#pragma once

//	HELO mr swoopae :DDDDDDDDDDDDDDDDDDDDDD

#include <cstdint>

#define stringify(x) #x
#define concat_impl(x, y) x##y
#define concat(x, y) concat_impl(x, y)

template<typename T, T v>
struct constant_holder {
	enum class val_holder : T {
		val = v
	};
};

#define constant(value) ((decltype(value))constant_holder<decltype(value), value>::val_holder::val)

constexpr static uint32_t seed = 0x45C3370D;
constexpr static uint32_t prime = 0x1000193;

inline uint32_t fnv1a_rt(const char* key, const uint32_t len) {
	const char* data = (char*)key;
	auto hash = seed;

	for (size_t i = 0; i < len; ++i) {
		const uint8_t val = (uint8_t)(data[i]);
		hash = hash ^ val;
		hash *= prime;
	}

	return hash;
}

constexpr uint32_t fnv1a_ct(const char* key, const uint32_t val = seed) {
	return !*key ? val : fnv1a_ct(key + 1, (unsigned)(1ull *
		(val ^ (std::uint8_t)*key) * prime));
}

#define HASH_CT(s) constant(fnv1a_ct(s))
#define HASH_RT(s) fnv1a_rt(s, strlen(s))