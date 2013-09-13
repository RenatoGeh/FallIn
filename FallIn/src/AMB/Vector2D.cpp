#include "Vector2D.hpp"
#include <cmath>
#include <iostream>

namespace amb {
	template <typename T>
	Vector2D<T>::Vector2D(T t) : x(t), y(t) {}
	
	template <typename T>
	Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {}

	template <typename T>
	Vector2D<T>::Vector2D(const Vector2D<T>& v) : x(v.x), y(v.y) {}
	
	template <typename T>
	Vector2D<T>::Vector2D(const ugdk::math::Vector2D& v) : x(v.x), y(v.y) {}
	
	template <typename T>
	Vector2D<T>& Vector2D<T>::rotate(double angle) {
		T tempX = x;
		double sin_ = sin(angle), cos_ = cos(angle);
		x = cos_ * x - sin_ * y;
		y = sin_ * tempX + cos_ * y;
		return *this;
	}
	
	template <typename T>
	std::ostream& operator << (std::ostream& stream, const Vector2D<T>& v) {
		stream << '[' << v.x << ", " << v.y << ']';
		return stream;
	}
	
	template class Vector2D<int>;
	template class Vector2D<double>;
}
