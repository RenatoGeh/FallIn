#ifndef MATH_HPP
#define	MATH_HPP
#include <iostream>

namespace amb {
	namespace math {		
		template <typename T>
		T abs(T);
		
		/* Calculates the integer part of the square root of the given unsigned integer
		 */
		unsigned sqrtFloor(unsigned n) {
			if(n == 0) return 0;
			unsigned x1 = (n + 1)/2;
			unsigned x2 = (x1*x1 + n)/(2*x1);
			while(x1 > x2) {
				x1 = x2;
				x2 = ((x2*x2 + n)/(2*x2));
			}
			return x1;
		}
		
		double sqrt(double n, double precision = 1e-5) {
			double x1 = n;
			double x2 = (x1 + n/x1)/2;
			while(x1 - x2 > precision) {
				x1 = x2;
				x2 = (x1 + n/x1)/2;
			}
			return x2;
		}
		
		template <typename T>
		inline T abs(T t) { return t > 0? t : -t; }
		
	}
}


#endif	/* MATH_HPP */

