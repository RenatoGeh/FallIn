#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include <iostream>
#include <cmath>
#include <ugdk/math/vector2D.h>

namespace amb {
	template <typename T = double> class Vector2D;

	template <typename T>
	using Point2D = Vector2D<T>;

	template <typename T>
	class Vector2D {
		public:
			union {
				struct{ T x, y; };
				struct{ T var[2]; };
			};
		public:
			explicit Vector2D(T = 0);
			Vector2D(T, T);
			Vector2D(const Vector2D<T>&);
			Vector2D(const ugdk::math::Vector2D&);
			Vector2D(const ugdk::math::Integer2D&);
		public:
			inline Vector2D<T>& set(T, T);
			inline Vector2D<T>& set(T t) { return set(t, t); }
			inline Vector2D<T>& operator = (const ugdk::math::Vector2D& v) { set(v.x, v.y); }
			inline Vector2D<T>& add(T, T);
			inline Vector2D<T>& add(T t) { return add(t, t); }
			inline Vector2D<T>& sub(T, T);
			inline Vector2D<T>& sub(T t) { return sub(t, t); }
			inline Vector2D<T>& mult(T, T);
			inline Vector2D<T>& mult(T t) { return mult(t, t); }
			inline Vector2D<T>& div(T, T);
			inline Vector2D<T>& div(T t) { return div(t, t); }
		public:
			inline Vector2D<T>& set(const Vector2D<T>& v) { return set(v.x, v.y); }
			inline Vector2D<T>& add(const Vector2D<T>& v) { return add(v.x, v.y); }
			inline Vector2D<T>& sub(const Vector2D<T>& v) { return sub(v.x, v.y); }
			inline T mult(const Vector2D<T>& v) const { return x * v.x + y * v.y; }
		public:
			inline T& operator [] (int index) { return var[index]; }
			inline Vector2D<T> operator + (const Vector2D<T>& v) const { return Vector2D<T>(x + v.x, y + v.y); }
			inline Vector2D<T> operator - (const Vector2D<T>& v) const { return Vector2D<T>(x - v.x, y - v.y); }
			inline T operator * (const Vector2D<T>& v) const { return mult(v); }
		public:
			inline Vector2D<T>& operator += (const Vector2D<T>& v) { return add(v); }
			inline Vector2D<T>& operator -= (const Vector2D<T>& v) { return sub(v); }
		public:
			inline bool operator == (const Vector2D<T>& v) const { return x == v.x && y == v.y; }
			inline bool operator != (const Vector2D<T>& v)const { return !(*this == v); }
			inline bool equals(T x, T y) const { return (this->x == x && this->y == y); }
			inline bool equals(const Vector2D<T>& v) const { return v == *this; }
		public:
			inline Vector2D<T>& operator *= (T t) { return mult(t); }
			inline Vector2D<T> operator * (T t) const { return Vector2D(x * t, y * t); }
			inline Vector2D<T>& operator /= (T t) { return div(t); }
			inline Vector2D<T> operator / (T t) const { return Vector2D(x / t, y / t); }
         inline Vector2D<T> operator - () const { return Vector2D(-x, -y); }
		public:
			inline Vector2D<T>& normalize() { return div(length()); }
			inline Vector2D<T> normalized() const { return Vector2D<T>(*this).normalize(); }
		public:
			inline T lengthSq() const { return x * x + y * y; }
			inline T length() const { return sqrt(lengthSq()); }
		public:
			inline T distSq(const Vector2D<T>& v) const { return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y); }
			inline T dist(const Vector2D<T>& v) const { return sqrt(distSq(v)); }
		public:
			Vector2D<T>& rotate(double);
			inline Vector2D<T> rotated(double angle) const { return Vector2D<T>(*this).rotate(angle); }
		public:
			operator ugdk::math::Vector2D() const { return ugdk::math::Vector2D(x, y); }
		public:
			inline bool inside(T x_, T y_, T w, T h) const { return !(x < x_ || x > x_ + w || y < y_ || y > y_ + h); }
			inline bool inside(const Vector2D<T>& pos, const Vector2D<T>& size) const { return inside(pos.x, pos.y, size.x, size.y); }
		public:
			inline void print(std::ostream& stream) { stream << '[' << x << ", " << y << ']'; }
	};
	
	template <typename T>
	inline Vector2D<T> operator * (T t, const Vector2D<T>& v) { return v * t; }

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
}

#endif