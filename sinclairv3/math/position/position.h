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
		T x, y, z;

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