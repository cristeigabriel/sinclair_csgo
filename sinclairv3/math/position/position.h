#pragma once

#include <cmath>

#include <corecrt_math.h>
#include <corecrt_math_defines.h>

namespace math {
	namespace util {
		constexpr static double pi = M_PI;
		constexpr static float pi_f = (float)M_PI;
	}

	namespace types {
		typedef unsigned int screen_2d_position;
	}

	template <typename T>
	struct point_t {
		constexpr point_t(T x = 0, T y = 0) : x(x), y(y) {}

		T x, y;

		inline T length() const {
			return sqrt(x * x + y * y);
		}

		inline T length_sqr() const {
			return (x * x + y * y);
		}

		inline math::point_t<T> operator+(const math::point_t<T>& v) const {
			return math::point_t<T>(x + v.x, y + v.y);
		}

		inline math::point_t<T> operator-(const math::point_t<T>& v) const {
			return point_t<T>(x - v.x, y - v.y);
		}

		inline math::point_t<T>& operator*=(T val) {
			x *= val;
			y *= val;
			return *this;
		}

		inline math::point_t<T>& operator*=(const math::point_t<T>& v) {
			x *= v.x;
			y *= v.y;
			return *this;
		}
	};

	template <typename T>
	struct point_3d_t {
		constexpr point_3d_t(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}

		T x, y, z;

		//	These could've used <algorithm>
		//	but I don't want to mix this datatype
		//	with functions that have special handling such as nodiscard,
		//	noexcept, etc

		inline void cstrike_clamp() {
			while (x > 89.f)
				x -= 180.f;
			while (x < -89.f)
				x += 180.f;

			while (y > 180.f)
				y -= 360.f;
			while (y < -180.f)
				y += 360.f;
		}

		inline void cstrike_normalize() {

			if (x > 89.f)
				x = 89.f;
			else if (x < -89.0f)
				x = -89.f;

			if (y > 180.f)
				y = 180.f;
			else if (y < -180.0f)
				y = -180.f;

			z = 0.f;
		}

		inline T length() const {
			return sqrt(x * x + y * y + z * z);
		}

		inline T length_2d() const {
			return sqrt(x * x + y * y);
		}

		inline T length_sqr() const {
			return (x * x + y * y + z * z);
		}

		inline T length_sqr_2d() const {
			return (x * x + y * y);
		}

		inline math::point_3d_t<T> operator+(const math::point_3d_t<T>& v) const {
			return math::point_3d_t<T>(x + v.x, y + v.y, z + v.z);
		}

		inline math::point_3d_t<T> operator-(const math::point_3d_t<T>& v) const {
			return math::point_3d_t<T>(x - v.x, y - v.y, z - v.z);
		}

		inline math::point_3d_t<T>& operator*=(T val) {
			x *= val;
			y *= val;
			z *= val;
			return *this;
		}

		inline math::point_3d_t<T>& operator*=(const math::point_3d_t<T>& v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}
	};

	template <typename T>
	struct point_4d_t {
		constexpr point_4d_t(T x = 0 , T y = 0, T z = 0, T v = 0) : x(x), y(y), z(z), v(v) {}

		T x, y, z, v;

		inline T length() const {
			return sqrt(x * x + y * y + z * z + v * v);
		}

		inline T length_2d() const {
			return sqrt(x * x + y * y);
		}

		inline T length_3d() const {
			return sqrt(x * x + y * y + z * z);
		}

		inline T length_sqr() const {
			return (x * x + y * y + z * z + v * v);
		}

		inline T length_sqr_2d() const {
			return (x * x + y * y);
		}

		inline T length_sqr_3d() const {
			return (x * x + y * y + z * z);
		}

		inline math::point_4d_t<T> operator+(const math::point_4d_t<T>& v) const {
			return math::point_4d_t<T>(x + v.x, y + v.y, z + v.z, this->v + v.v);
		}

		inline math::point_4d_t<T> operator-(const math::point_4d_t<T>& v) const {
			return math::point_4d_t<T>(x - v.x, y - v.y, z - v.z, this->v + v.v);
		}

		inline math::point_4d_t<T>& operator*=(T val) {
			x *= val;
			y *= val;
			z *= val;
			v *= val;
			return *this;
		}

		inline math::point_4d_t<T>& operator*=(const math::point_4d_t<T>& v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
			this->v *= v.v;
			return *this;
		}
	};
}