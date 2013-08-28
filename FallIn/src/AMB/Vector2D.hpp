/*
 * Vector2D.hpp
 *
 *  Created on: Aug 28, 2013
 *      Author: renatogeh
 */

#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include <iostream>

namespace amb {

	template <typename T>
	class Vector2D {
		public:
			T x;
			T y;
		public:
			Vector2D(T, T);
			Vector2D(const Vector2D<T>&);
		public:
			inline Vector2D<T>& set(T, T);
			inline Vector2D<T>& add(T, T);
			inline Vector2D<T>& sub(T, T);
			inline Vector2D<T>& mult(T, T);
			inline Vector2D<T>& div(T, T);
		public:
			inline Vector2D<T>& set(const Vector2D<T>&);
			inline Vector2D<T>& add(const Vector2D<T>&);
			inline Vector2D<T>& sub(const Vector2D<T>&);
			inline T mult(const Vector2D<T>&) const;
			inline Vector2D<T>& div(const Vector2D<T>&);
		public:
			inline T operator [] (const Vector2D<T>&) const;
			inline Vector2D operator + (const Vector2D<T>&) const;
			inline Vector2D operator - (const Vector2D<T>&) const;
			inline T operator * (const Vector2D<T>&) const;
			//inline Vector2D operator / (const Vector2D<T>&) const;
		public:
			inline Vector2D<T>& operator += (const Vector2D<T>&);
			inline Vector2D<T>& operator -= (const Vector2D<T>&);
			inline Vector2D<T>& operator *= (const Vector2D<T>&);
			inline Vector2D<T>& operator /= (const Vector2D<T>&);
		public:
			inline Vector2D<T>& normalize(void);
			inline Vector2D<T> normalized(void) const;
		public:
			inline T lengthSq(void) const;
			inline T length(void) const;
		public:
			inline T distSq(const Vector2D<T>&) const;
			inline T dist(const Vector2D<T>&) const;
		public:
			inline Vector2D<T>& rotate(double);
			inline Vector2D<T> rotated(double) const;
	};

	template <typename T>
	Vector2D<T>::Vector2D(T x = 0, T y = 0) : x(x), y(y) {};

	template <typename T>
	Vector2D<T>::Vector2D(const Vector2D<T>& v) : x(v.x), y(v.y) {};

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::set(T x, T y) {
		this->x = x;
		this->y = y;
		return *this;
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::add(T x, T y) {
		this->x += x;
		this->y += y;
		return *this;
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::sub(T x, T y) {
		this->x -= x;
		this->y -= y;
		return *this;
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::mult(T x, T y) {
		this->x *= x;
		this->y *= y;
		return *this;
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::div(T x, T y) {
		this->x /= x;
		this->y /= y;
		return *this;
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::set(const Vector2D<T>& v) {
		return set(v.x, v.y);
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::add(const Vector2D<T>& v) {
		return add(v.x, v.y);
	}

	template <typename T>
	inline Vector2D<T>& Vector2D<T>::sub(const Vector2D<T>& v) {
		return sub(v.x, v.y);
	}

	template <typename T>
	inline T Vector2D<T>::mult(const Vector2D<T>& v) const {
		return this->x*v.x + this->y*v.y;
	}

	template <typename T>
	std::ostream& operator << (const std::ostream& stream, const Vector2D<T>& v) {
		stream << '[' << v.x << ", " << v.y << ']';
	}
}

#endif
